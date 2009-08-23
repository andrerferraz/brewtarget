/*
 * mash.h is part of Brewtarget, and is Copyright Philip G. Lee
 * (rocketman768@gmail.com), 2009.
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

#ifndef _MASH_H
#define _MASH_H
#include <string>
#include <exception>
#include "xmlnode.h"
#include "mashstep.h"
#include "observable.h"
#include <QDomNode>
#include "BeerXMLElement.h"

class Mash;
class MashException;

class Mash : public Observable, public MultipleObserver, public BeerXMLElement
{
public:

   Mash();
   Mash( const XmlNode *node);
   Mash( const QDomNode& mashNode );

   friend bool operator<(Mash &m1, Mash &m2);
   friend bool operator==(Mash &m1, Mash &m2);

   virtual void toXml(QDomDocument& doc, QDomNode& parent); // From BeerXMLElement
   virtual void notify(Observable *notifier, QVariant info); // From MultipleObserver
   
   void setName( const std::string &var );
   void setGrainTemp_c( double var );
   void setNotes( const std::string &var );
   void setTunTemp_c( double var );
   void setSpargeTemp_c( double var );
   void setPh( double var );
   void setTunWeight_kg( double var );
   void setTunSpecificHeat_calGC( double var );
   void setEquipAdjust( bool var );

   std::string getName() const;
   double getGrainTemp_c() const;
   unsigned int getNumMashSteps() const;
   MashStep* getMashStep( unsigned int i );
   std::string getNotes() const;
   double getTunTemp_c() const;
   double getSpargeTemp_c() const;
   double getPh() const;
   double getTunWeight_kg() const;
   double getTunSpecificHeat_calGC() const;
   bool getEquipAdjust() const;

   void addMashStep(MashStep* step);
   void removeMashStep(MashStep* step);
   double totalMashWater_l() const; // Total amount of water that went INTO the mash.
private:

   std::string name;
   static const int version = 1;
   double grainTemp_c;
   std::vector<MashStep *> mashSteps;
   std::string notes;
   double tunTemp_c;
   double spargeTemp_c;
   double ph;
   double tunWeight_kg;
   double tunSpecificHeat_calGC;
   bool equipAdjust;
   
   void setDefaults();

};

class MashException : public std::exception
{
public:

   virtual const char* what() const throw()
   {
      return std::string("BeerXML ... error: " + _err + "\n").c_str();
   }

   MashException( std::string message )
   {
      _err = message;
   }

   ~MashException() throw() {}

private:

   std::string _err;
};

struct Mash_ptr_cmp
{
   bool operator()( Mash* lhs, Mash* rhs)
   {
      return *lhs < *rhs;
   }
};

struct Mash_ptr_equals
{
   bool operator()( Mash* lhs, Mash* rhs )
   {
      return *lhs == *rhs;
   }
};

#endif //_MASH_H