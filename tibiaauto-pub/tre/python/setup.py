# setup.py - Builds and installs the TRE Python language bindings module
#
# Copyright (C) 2004 Nikolai SAOUKH <nms+python@otdel-1.org>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 2 (June
# 1991) as published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

from distutils.core import setup, Extension
import sys
from glob import glob
from os.path import normpath
import re

def ospath(fl):
    return [normpath(f) for f in fl]

VERSION = "0.7.2"

SOURCES = ["tre-python.c"]

INCDIRS = ospath(["..", "../lib"])

setup(
    name = "tre",
    version = VERSION,
    description = "Python module for TRE",
    author = "Nikolai SAOUKH",
    author_email = "nms+python@otdel-1.org",
    license = "GPL",
    url = "http://laurikari.net/tre/",
    ext_modules = [
        Extension(
            "tre",
	    SOURCES,
	    include_dirs = INCDIRS,
            define_macros = [("HAVE_CONFIG_H", None)],
	    libraries=["tre"]
	),
    ],
)
