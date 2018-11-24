/*****************************************************************************
 *
 * config.h -- declaration of data structures for configuration data
 *
 * Copyright 2013,2014,2015,2016,2017,2018
 *     James Fidell (james@openastroproject.org)
 *
 * License:
 *
 * This file is part of the Open Astro Project.
 *
 * The Open Astro Project is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * The Open Astro Project is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the Open Astro Project.  If not, see
 * <http://www.gnu.org/licenses/>.
 *
 *****************************************************************************/

#pragma once

#if HAVE_LIMITS_H
#include <limits.h>
#endif

extern "C" {
#include <openastro/camera.h>
#include <openastro/filterwheel.h>
#include <openastro/userConfig.h>
}

#define	CONFIG_VERSION	2

#include "profile.h"

typedef QList<userDeviceConfig> userConfigList;

typedef struct
{
  // general
  int			saveSettings;
  int			tempsInC;
  int			connectSoleCamera;

  // settings from device menu
  int			cameraDevice;

  // options menu
  int			showHistogram;
  int			showReticle;
  int			showFocusAid;
  int			derotate;
  int			flipX;
  int			flipY;
  int			demosaic;

  // camera config
  unsigned int		inputFrameFormat;
  unsigned int		forceInputFrameFormat;
  int			binning2x2;

  // image config
  int			useROI;
  unsigned int		imageSizeX;
  unsigned int		imageSizeY;
  int			colourise;
  QColor		currentColouriseColour;
  int			numCustomColours;
  QList<QColor>		customColours;

  // zoom config
  int			zoomButton1Option;
  int			zoomButton2Option;
  int			zoomButton3Option;
  int			zoomValue;

  // control config
  int64_t		controlValues[OA_CAM_CTRL_MODIFIERS_P1][ OA_CAM_CTRL_LAST_P1 ];
  int			exposureMenuOption;
  int			frameRateNumerator;
  int			frameRateDenominator;
  int			selectableControl[2];
  int			intervalMenuOption;

  // capture config
  int			profileOption;
  int			filterOption;
  int			fileTypeOption;
  QString		frameFileNameTemplate;
  QString		processedFileNameTemplate;
  QString		captureDirectory;
  int			saveEachFrame;
  int			saveProcessedImage;
  int			saveCaptureSettings;
  int			indexDigits;

  // reticle config
  int			reticleStyle;

  // saved profiles
  int			numProfiles;
  QList<PROFILE>	profiles;

  // filters
  int			numFilters;
  QList<FILTER>		filters;
  int			filterSlots[MAX_FILTER_SLOTS];
  int			promptForFilterChange;
  int			interFilterDelay;

  // advanced user configuration

  QList<userConfigList>	filterWheelConfig;

} CONFIG;

extern CONFIG		config;

#define CONTROL_VALUE(c)	controlValues[OA_CAM_CTRL_MODIFIER(c)][OA_CAM_CTRL_MODE_BASE(c)]
