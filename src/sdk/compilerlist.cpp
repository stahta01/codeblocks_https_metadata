/*
 * This file is part of the Code::Blocks IDE and licensed under the GNU Lesser General Public License, version 3
 * http://www.gnu.org/licenses/lgpl-3.0.html
 *
 */

#include <wx/choice.h>

#include "compilerlist.h"
#include "compilerfactory.h"

#include "compiler.h" // Compiler

// statics
wxChoice CompilerList::Compilers;
Compiler* CompilerList::s_DefaultCompiler = nullptr;

std::size_t CompilerList::GetCompilersCount()
{
    return Compilers.GetCount();
}

Compiler* CompilerList::GetCompiler(CompilerListIndex index)
{
    // NOTE: The index can be -1 , if there is no compiler at all or less than number of compilers.
    /* NOTE: Any negative value of index will be converted to a large unsigned integer.
    Therefore it's safe to check if the index equals or exceeds the compiler count. */
    if ((Compilers.GetCount() < 1) || (index >= Compilers.GetCount()))
        return nullptr;
    return (Compiler*) Compilers.GetClientData(index);
}

Compiler* CompilerList::GetCompiler(const wxString& id)
{
    const wxString lid = id.Lower();
    Compiler* pCompiler = nullptr;
    for (size_t i = 0; i < Compilers.GetCount(); ++i)
    {
        pCompiler = (Compiler*) Compilers.GetClientData(i);
        if (pCompiler->GetID().IsSameAs(lid))
            return pCompiler;
    }
    return nullptr;
}


CompilerListIndex CompilerList::GetCompilerIndex(const wxString& id)
{
    const wxString lid = id.Lower();
    Compiler* pCompiler = nullptr;
    for (size_t i = 0; i < Compilers.GetCount(); ++i)
    {
        pCompiler = (Compiler*) Compilers.GetClientData(i);
        if (pCompiler->GetID().IsSameAs(lid))
            return i;
    }
    return -1;
}

CompilerListIndex CompilerList::GetCompilerIndex(Compiler* compiler)
{
    Compiler* pCompiler = nullptr;
    for (size_t i = 0; i < Compilers.GetCount(); ++i)
    {
        pCompiler = (Compiler*) Compilers.GetClientData(i);
        if (pCompiler == compiler)
            return i;
    }
    return -1;
}

const wxString& CompilerList::GetDefaultCompilerID()
{
    if (s_DefaultCompiler)
        return s_DefaultCompiler->GetID();

    static wxString empty = wxEmptyString;
    return empty;
}

Compiler* CompilerList::GetDefaultCompiler()
{
    return s_DefaultCompiler;
}

void CompilerList::SetDefaultCompiler(CompilerListIndex index)
{
    if ((Compilers.GetCount() > 0) && (index < Compilers.GetCount())){
        s_DefaultCompiler = (Compiler*) Compilers.GetClientData(index);
    }
}

void CompilerList::SaveSettings()
{
}

Compiler* CompilerList::CreateCompilerCopy(Compiler* compiler, const wxString& newName)
{
    if (!compiler)
        return nullptr;
#if 0
    // abort if an existing compiler with the same name exists
    // this also avoids the possibility of throwing an exception
    // in the compiler->CreateCopy() call below...
    for (size_t i = 0; i < Compilers.GetCount(); ++i)
    {
        if (Compilers[i]->GetName() == newName)
            return nullptr;
    }

    Compiler* newC = compiler->CreateCopy();
    if (!newName.IsEmpty())
    {
        Compiler::m_CompilerIDs.Remove(newC->GetID());
        newC->SetName(newName);
        newC->m_ID = newName;
        newC->MakeValidID();
    }
    newC->ReloadOptions();
    RegisterCompiler(newC);
    newC->LoadSettings(_T("/user_sets"));
    Manager::Get()->GetLogManager()->DebugLog(F(_T("Added compiler \"%s\""), newC->GetName().wx_str()));
    return newC; // return the index for the new compiler
#endif
}


void CompilerList::RemoveListedCompiler(Compiler* compiler)
{
    if (!compiler)
        return;

}


void CompilerList::RemoveRegisteredCompiler(Compiler* compiler)
{
    if (!compiler)
        return;
    RemoveListedCompiler(compiler);
    CompilerFactory::RemoveCompiler(compiler);
    SaveSettings();
}

Compiler* CompilerList::SelectCompilerUI(const wxString& message, const wxString& preselectedID)
{
    int selected = -1;
    const wxString lid = preselectedID.Lower();

#if 0
    // first build a list of available compilers
    wxString* comps = new wxString[Compilers.GetCount()];
    for (size_t i = 0; i < Compilers.GetCount(); ++i)
    {
        comps[i] = Compilers[i]->GetName();
        if (selected == -1)
        {
            if (lid.IsEmpty())
            {
                if (Compilers[i] == s_DefaultCompiler)
                    selected = i;
            }
            else
            {
                if (Compilers[i]->GetID().IsSameAs(lid))
                    selected = i;
            }
        }
    }
    // now display a choice dialog
    wxSingleChoiceDialog dlg(nullptr,
                             message,
                             _("Compiler selection"),
                             CompilerList::Compilers.GetCount(),
                             comps);
    dlg.SetSelection(selected);
    PlaceWindow(&dlg);
    if (dlg.ShowModal() == wxID_OK)
        return Compilers[dlg.GetSelection()];
#endif
    return nullptr;
}
