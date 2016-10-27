/*
 * This file is part of the Code::Blocks IDE and licensed under the GNU Lesser General Public License, version 3
 * http://www.gnu.org/licenses/lgpl-3.0.html
 */

#ifndef COMPILERLIST_H
#define COMPILERLIST_H

#include <cstddef> // size_t

#include <wx/choice.h>

#include "settings.h"

typedef signed char CompilerListIndex;

class Compiler;

class DLLIMPORT CompilerList
{
    public:
        /// @return the number of listed compilers.
        static std::size_t GetCompilersCount();
        /// @return the compiler by an index.
        static Compiler* GetCompiler(CompilerListIndex index);
        /// @return the compiler by a name (ID). *Not* the compiler's title...
        static Compiler* GetCompiler(const wxString& id);

        /// @return the compiler's index from its id. Returns -1 if it doesn't exist.
        static CompilerListIndex GetCompilerIndex(const wxString& id);
        /// @return the compiler's index. Returns -1 if it doesn't exist.
        static CompilerListIndex GetCompilerIndex(Compiler* compiler);

        /// Create a copy of a compiler.
        static Compiler* CreateCompilerCopy(Compiler* compiler, const wxString& newName);

        /// Remove a Registered compiler.
        static void RemoveRegisteredCompiler(Compiler* compiler);

        /// Remove a Listed compiler.
        static void RemoveListedCompiler(Compiler* compiler);

        static void SaveSettings();

        static const wxString& GetDefaultCompilerID();
        static Compiler* GetDefaultCompiler();
        static void SetDefaultCompiler(CompilerListIndex index);

        static Compiler* SelectCompilerUI(const wxString& message = _("Select compiler"), const wxString& preselectedID = wxEmptyString);
    private:
        static wxChoice Compilers;
        static Compiler* s_DefaultCompiler;
};

#endif // COMPILERLIST_H
