# Find the native QRealFourier includes and library
#
# This module defines
#  QREALFOURIER_INCLUDE_DIR: QRealFourier headers
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

	GET_FILENAME_COMPONENT(THIS "${CMAKE_CURRENT_LIST_FILE}" PATH)
	FIND_PATH(QREALFOURIER_INCLUDE_DIR qfouriertransformer.h /usr/include/qrealfourier)

	SET(QREALFOURIER_NAMES ${QREALFOURIER_NAMES} qrealfourier libqrealfourier)
	FIND_LIBRARY(QREALFOURIER_LIBRARY NAMES ${QREALFOURIER_NAMES} PATHS ${THIS})

	IF(QREALFOURIER_LIBRARY AND QREALFOURIER_INCLUDE_DIR)
		SET(QREALFOURIER_FOUND "TRUE")
	ENDIF(QREALFOURIER_LIBRARY AND QREALFOURIER_INCLUDE_DIR)

ENDIF(QT_QTCORE_FOUND)

MARK_AS_ADVANCED(QRealFourier_DIR)
