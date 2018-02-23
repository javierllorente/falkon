/* ============================================================
* Falkon - Qt web browser
* Copyright (C) 2014  David Rosca <nowrep@gmail.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
* ============================================================ */
#ifndef DATAPATHS_H
#define DATAPATHS_H

#include <QStringList>

#include "qzcommon.h"

class QTemporaryDir;

class FALKON_EXPORT DataPaths
{
public:
    enum Path {
        AppData = 0,             // /usr/share/falkon or . or ../Resources
        Translations = 1,        // $AppData/locale
        Themes = 2,              // $AppData/themes
        Plugins = 3,             // $AppData/plugins
        Config = 4,              // $XDG_CONFIG_HOME/falkon or %LOCALAPPDATA%/falkon or $AppData/data (portable)
        Profiles = 5,            // $Config/profiles
        CurrentProfile = 6,      // $Profiles/current_profile
        Temp = 7,                // $Config/tmp
        Cache = 8,               // $XDG_CACHE_HOME/falkon or $CurrentProfile/cache
        Sessions = 9,            // $CurrentProfile/sessions
        LastPath = 10
    };

    explicit DataPaths();
    ~DataPaths();

    // Set absolute path of current profile
    static void setCurrentProfilePath(const QString &profilePath);
    // Set Config path to $AppData/data
    static void setPortableVersion();

    // Returns main path (Themes -> /usr/share/themes)
    static QString path(Path type);
    // Returns all paths (Themes -> /usr/share/themes, ~/.config/falkon/themes)
    static QStringList allPaths(Path type);
    // Returns full path of existing file
    static QString locate(Path type, const QString &file);
    // Convenience function for getting CurrentProfile
    static QString currentProfilePath();

private:
    void init();
    void initCurrentProfile(const QString &profilePath);
    void initAssetsIn(const QString &path);

    QStringList m_paths[LastPath];
    QScopedPointer<QTemporaryDir> m_tmpdir;
};

#endif // DATAPATHS_H
