# Find the native QRealFourier includes and library
#
# This module defines
#  QREALFOURIER_INCLUDE_DIR: QRealFourier headers
#  QREALFOURIER_LIBRARIES: Libraries for linking to QRealFourier
#  QREALFOURIER_LIBRARY: QRealFourier library
#  QREALFOURIER_FOUND: If QRealFourier was found or not

#=============================================================================
# Copyright 2011-2012 Christoph Stallmann
#
# University of Pretoria
# Department of Computer Science
#
# Distributed under the GNU Lesser General Public License Version 3 (LGPLv3)
#
# This software is distributed WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#=============================================================================

FIND_PACKAGE(Qt COMPONENTS Core REQUIRED)

IF(QT_QTCORE_FOUND)

	FIND_PATH(QREALFOURIER_INCLUDE_DIR qfouriertransformer.h /usr/include/qrealfourier)

	SET(QREALFOURIER_NAMES ${QREALFOURIER_NAMES} qrealfourier libqrealfourier)
	FIND_LIBRARY(QREALFOURIER_LIBRARY NAMES ${QREALFOURIER_NAMES})

	IF(QREALFOURIER_LIBRARY AND QREALFOURIER_INCLUDE_DIR)
		SET(QREALFOURIER_INCLUDE_DIR ${QREALFOURIER_INCLUDE_DIR} ${QT_QTCORE_INCLUDE_DIR})
		SET(QREALFOURIER_LIBRARIES ${QREALFOURIER_LIBRARY} ${QT_QTCORE_LIBRARY})
	ENDIF(QREALFOURIER_LIBRARY AND QREALFOURIER_INCLUDE_DIR)

ENDIF(QT_QTCORE_FOUND)

# Handle the QUIETLY and REQUIRED arguments and set QREALFOURIER_FOUND to TRUE if 
# all listed variables are TRUE
INCLUDE(${CMAKE_CURRENT_LIST_DIR}/FindPackageHandleStandardArgs.cmake)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(QREALFOURIER DEFAULT_MSG QREALFOURIER_LIBRARY QREALFOURIER_INCLUDE_DIR)

MARK_AS_ADVANCED(QREALFOURIER_INCLUDE_DIR QREALFOURIER_LIBRARY)
