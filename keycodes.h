/* Copyright 2022 toinux
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#pragma once

enum crkbd_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _META,
  _GAMING,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define BASE DF(_BASE)
#define META MO(_META)
#define GAMING TG(_GAMING)
