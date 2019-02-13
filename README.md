# ShellXplorer

## Overview

ShellXplorer is a terminal emulator that aims to merge the power of the linux shell with the ergonomy of graphic file explorers.

It is largely based on [QTerminal](https://github.com/lxqt/qterminal), a great Qt-based terminal emulator maintained by the LXQt project.

This project is licensed under the terms of the [GPLv2](https://www.gnu.org/licenses/gpl-2.0.en.html) or any later version. See the LICENSE file for the full text of the license.

## Installation

### Compiling sources

Dependencies are qtx11extras ≥ 5.2 and [QTermWidget](https://github.com/lxqt/qtermwidget).
In order to build CMake ≥ 3.0.2 and [lxqt-build-tools](https://github.com/lxqt/lxqt-build-tools) are needed as well as optionally Git to pull latest VCS checkouts. The localization files were outsourced to repository [lxqt-l10n](https://github.com/lxqt/lxqt-l10n) so the corresponding dependencies are needed, too. Please refer to this repository's `README.md` for further information.

Code configuration is handled by CMake. Building out of source is required. CMake variable `CMAKE_INSTALL_PREFIX` will normally have to be set to `/usr`.

How to build ?
* mkdir build && cd build
* cmake ..
* run `make`, to install `make install` which accepts variable `DESTDIR` as usual.

