/* ============================================================
* Falkon - Qt web browser
* Copyright (C) 2018 Anmol Gautam <tarptaeya@gmail.com>
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
#ifndef QMLPLUGINS_H
#define QMLPLUGINS_H

class QmlPlugins
{
    static void registerQmlPluginInterface();

    static void registerQmlBookmarkTreeNode();
    static void registerQmlBookmarks();

    static void registerQmlMostVisitedUrl();
    static void registerQmlTopSites();

    static void registerQmlHistoryItem();
    static void registerQmlHistory();

    static void registerQmlCookie();
    static void registerQmlCookies();
public:
    static void registerQmlTypes();
};

#endif // QMLPLUGINS_H