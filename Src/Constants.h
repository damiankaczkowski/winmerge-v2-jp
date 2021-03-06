/** 
 * @file Constants.h
 *
 * @brief WinMerge constants, URLs, paths etc.
 *
 */
#pragma once

/** @brief URL for hyperlink in About-dialog. */
const TCHAR WinMergeURL[] = _T("http://www.geocities.co.jp/SiliconValley-SanJose/8165/winmerge.html");

/**
 * @brief URL to help index in internet.
 * We use internet help when local help file is not found (not installed).
 */
const TCHAR DocsURL[] = _T("http://manual.winmerge.org/index.html");

/** @brief URL of the GPL license. */
const TCHAR LicenceUrl[] = _T("http://www.gnu.org/licenses/gpl-2.0.html");

/** @brief WinMerge download page URL. */
const TCHAR DownloadUrl[] = _T("http://www.geocities.co.jp/SiliconValley-SanJose/8165/winmerge.html#downloads");

const TCHAR CurrentVersionURL[] = _T("http://www.geocities.co.jp/SiliconValley-SanJose/8165/winmerge-jp_current_version.txt");

/** @brief Relative (to WinMerge executable ) path to local help file. */
const TCHAR DocsPath[] = _T("Docs/WinMerge.chm");
const TCHAR DocsPath_ja[] = _T("Docs/WinMerge_ja.chm");

/** @brief Contributors list. */
const TCHAR ContributorsPath[] = _T("contributors.txt");

/** @brief GPL Licence local file name. */
const TCHAR LicenseFile[] = _T("Copying");

/** @brief WinMerge folder in My Folders-folder. */
const TCHAR WinMergeDocumentsFolder[] = _T("WinMerge");

/**
 * @brief Default relative path to "My Documents" for private filters.
 * We want to use WinMerge folder as general user-file folder in future.
 * So it makes sense to have own subfolder for filters.
 */
const TCHAR DefaultRelativeFilterPath[] = _T("WinMerge/Filters");

/** @brief Executable Filename for ANSI build. */
const TCHAR ExecutableFilename[] = _T("WinMerge.exe");
/** @brief Executable Filename for Unicode build. */
const TCHAR ExecutableFilenameU[] = _T("WinMergeU.exe");

/** @brief Temp folder name prefix for WinMerge temp folders. */
const TCHAR TempFolderPrefix[] = _T("WinMerge_TEMP_");

/** @brief registry dir to WinMerge */
const TCHAR RegDir[] = _T("Software\\Thingamahoochie\\WinMerge");

/**
 * @brief Flags used when opening files
 */
enum
{
	FFILEOPEN_NONE		= 0x0000,
	FFILEOPEN_NOMRU		= 0x0001, /**< Do not add this path to MRU list */
	FFILEOPEN_READONLY	= 0x0002, /**< Open this path as read-only */
	FFILEOPEN_MODIFIED  = 0x0004, /**< Mark file modified after opening. */
	FFILEOPEN_CMDLINE	= 0x0010, /**< Path is read from commandline */
	FFILEOPEN_PROJECT	= 0x0020, /**< Path is read from project-file */
	FFILEOPEN_SETFOCUS  = 0x0040, /**< Set focus to this pane */
	FFILEOPEN_AUTOMERGE = 0x0080, /**< auto-merge at this pane */
};
