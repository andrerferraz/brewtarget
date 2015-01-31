/*
 * SgDensityUnitSystem.cpp part of Brewtarget, and was written by Mik
 * Firestone (mikfire@gmail.com), copyright 2014-2019
 *
 * Brewtarget is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * Brewtarget is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "SgDensityUnitSystem.h"
#include <QStringList>
#include "unit.h"

SgDensityUnitSystem::SgDensityUnitSystem()
   : UnitSystem()
{
   _type = Density;
}

void SgDensityUnitSystem::loadMap() { scaleToUnit.insert(scaleWithout,Units::sp_grav); }
void SgDensityUnitSystem::loadUnitmap() { qstringToUnit.insert("sg",Units::sp_grav); }

QString SgDensityUnitSystem::unitType() { return "Density"; }
Unit* SgDensityUnitSystem::unit() { return Units::sp_grav; }