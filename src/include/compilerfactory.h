/*
 * This file is part of the Code::Blocks IDE and licensed under the GNU Lesser General Public License, version 3
 * http://www.gnu.org/licenses/lgpl-3.0.html
 */

#ifndef COMPILERFACTORY_H
#define COMPILERFACTORY_H

#include <wx/arrstr.h> // WX_DEFINE_ARRAY
#include "compiler.h" // Compiler

#include "settings.h"

class Compiler;

typedef signed short int CompilerListedIndex;
typedef signed long int CompilerIndex;
typedef wxString CompilerID;

// Well, not really a factory ;)

WX_DEFINE_ARRAY(Compiler*, CompilersArray);

class DLLIMPORT CompilerFactory
{
    public:
        /// @return the number of registered compilers.
        static size_t GetCompilersCount();
        /// @return the registered compiler by an index.
        static Compiler* GetCompiler(CompilerIndex index);
        /// @return the registered compiler by a name (ID). *Not* the compiler's title...
        static Compiler* GetCompiler(const wxString& id);
        /// @return the registered compiler by title.
        static Compiler* GetCompilerByName(const wxString& title);

        /// @return the number of listed compilers.
        static size_t GetListedCompilersCount();
        /// @return the listed compiler by an index.
        static Compiler* GetListedCompiler(CompilerListedIndex index);
        /// @return the listed compiler's index from its id. Returns -1 if it doesn't exist.
        static CompilerListedIndex GetListedCompilerIndex(const wxString& id);
        /// Remove a listed compiler.
        static void RemoveListedCompiler(Compiler* compiler);
        /// Add a listed compiler from registered ID.
        static void AddListedCompiler(const wxString& registeredId);
        static void SaveListedSettings();
        static void LoadListedSettings();

        /// @return the registered compiler's index from its id. Returns -1 if it doesn't exist.
        static CompilerIndex GetCompilerIndex(const wxString& id);
        /// @return the registered compiler's index. Returns -1 if it doesn't exist.
        static CompilerIndex GetCompilerIndex(Compiler* compiler);

        /// @return true if the specified registered compiler ID is valid, false if not.
        static bool IsValidCompilerID(const wxString& id){ return GetCompilerIndex(id) != -1; }

        /// @return true if registered compiler ID @c id inherits, directly or indirectly, from compiler ID @c from_id.
        static bool CompilerInheritsFrom(const wxString& id, const wxString& from_id);
        /// @return true if @c registered compiler inherits, directly or indirectly, from compiler ID @c from_id.
        static bool CompilerInheritsFrom(Compiler* compiler, const wxString& from_id);

        /// Register a supported (builtin) compiler.
        static void RegisterCompiler(Compiler* compiler);
        /// Register all user-defined compiler copies.
        static void RegisterUserCompilers();
        /// Create a copy of a compiler.
        static Compiler* CreateCompilerCopy(Compiler* compiler, const wxString& newName);
        /// Remove a compiler.
        static void RemoveCompiler(Compiler* compiler);
        /// Unregister all compilers.
        static void UnregisterCompilers();
        /// get the version number as string for the compiler with the specified ID
        static wxString GetCompilerVersionString(const wxString& Id);

        static void SaveSettings();
        static void LoadSettings();

        static const wxString& GetDefaultCompilerID();
        static Compiler* GetDefaultCompiler();
        static void SetDefaultCompiler(CompilerIndex index);
        static void SetDefaultCompiler(const wxString& id);
        static void SetDefaultCompiler(Compiler* compiler);

        static Compiler* SelectCompilerUI(const wxString& message = _("Select compiler"), const wxString& preselectedID = wxEmptyString);
    private:
        static CompilersArray Compilers;
        static CompilersArray ListedCompilers;
        static Compiler* s_DefaultCompiler;
        static wxArrayString ListedCompilerIDs;
};

#endif // COMPILERFACTORY_H
