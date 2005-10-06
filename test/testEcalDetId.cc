/**
   \file
   Test suit for EcalDetId

   \version $Id: testEcalDetId.cc,v 1.1 2005/07/27 10:36:11 meridian Exp $

   \note This test is not exaustive     
*/

static const char CVSId[] = "$Id: testEcalDetId.cc,v 1.1 2005/07/27 10:36:11 meridian Exp $";

#include <cppunit/extensions/HelperMacros.h>
#include <DataFormats/EcalDetId/interface/EBDetId.h>
#include <DataFormats/EcalDetId/interface/EEDetId.h>
#include <DataFormats/EcalDetId/interface/ESDetId.h>
#include <DataFormats/EcalDetId/interface/EcalTrigTowerDetId.h>

#include <iostream>

class testEcalDetId: public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(testEcalDetId);

  CPPUNIT_TEST(testEBDetId);
  CPPUNIT_TEST(testEEDetId);
  CPPUNIT_TEST(testESDetId);
  CPPUNIT_TEST(testEcalTrigTowerDetId);

  CPPUNIT_TEST_SUITE_END();

public:


  void setUp(){}
  void tearDown(){}  
  void testEBDetId();
  void testEEDetId();
  void testESDetId();
  void testEcalTrigTowerDetId();
 
}; 

///registration of the test so that the runner can find it
CPPUNIT_TEST_SUITE_REGISTRATION(testEcalDetId);

void testEcalDetId::testEBDetId(){


  for (int ieta=1;ieta<=EBDetId::MAX_IETA;ieta++)
      for (int iphi=1;iphi<=EBDetId::MAX_IPHI;iphi++)
	{
	  //EBDetId Zside 1 
	  {
	    EBDetId aPositiveId(ieta,iphi);
	    CPPUNIT_ASSERT(aPositiveId.ieta()==ieta);
	    CPPUNIT_ASSERT(aPositiveId.iphi()==iphi);
	    CPPUNIT_ASSERT(aPositiveId.zside()==1);
	    CPPUNIT_ASSERT(aPositiveId.ietaAbs()==ieta);
	  }
	  //EBDetId Zside -1 
	  {
	    EBDetId aNegativeId(-1*ieta,iphi);
	    CPPUNIT_ASSERT(aNegativeId.ieta()==-1*ieta);
	    CPPUNIT_ASSERT(aNegativeId.iphi()==iphi);
	    CPPUNIT_ASSERT(aNegativeId.zside()==-1);
	    CPPUNIT_ASSERT(aNegativeId.ietaAbs()==ieta);
	  }
	}
  
}

void testEcalDetId::testEEDetId(){
  
  
  for (int ix=EEDetId::IX_MIN;ix<=EEDetId::IX_MAX;ix++)
    for (int iy=EEDetId::IY_MIN;iy<=EEDetId::IY_MAX;iy++)
      {
	//EEDetId Zside 1 
	{
	  EEDetId aPositiveId(ix,iy,1);
	  CPPUNIT_ASSERT(aPositiveId.ix()==ix);
	  CPPUNIT_ASSERT(aPositiveId.iy()==iy);
	  CPPUNIT_ASSERT(aPositiveId.zside()==1);
	}
	//EEDetId Zside -1 
	{
	  EEDetId aNegativeId(ix,iy,-1);
	  CPPUNIT_ASSERT(aNegativeId.ix()==ix);
	  CPPUNIT_ASSERT(aNegativeId.iy()==iy);
	  CPPUNIT_ASSERT(aNegativeId.zside()==-1);
	}
      }
  
}

void testEcalDetId::testESDetId(){
  
  
  for (int istrip=ESDetId::ISTRIP_MIN;istrip<=ESDetId::ISTRIP_MAX;istrip++)
    for (int ix=ESDetId::IX_MIN;ix<=ESDetId::IX_MAX;ix++)
      for (int iy=ESDetId::IY_MIN;iy<=ESDetId::IY_MAX;iy++)
      {
	//ESDetId Plane 0 Zside 1 
	{
	  ESDetId aPositiveId(istrip,ix,iy,0,1);
	  CPPUNIT_ASSERT(aPositiveId.strip()==istrip);
	  CPPUNIT_ASSERT(aPositiveId.six()==ix);
	  CPPUNIT_ASSERT(aPositiveId.siy()==iy);
	  CPPUNIT_ASSERT(aPositiveId.plane()==0);
	  CPPUNIT_ASSERT(aPositiveId.zside()==1);

	}
	//ESDetId Plane 1 Zside 1 
	{
	  ESDetId aPositiveId(istrip,ix,iy,1,1);
	  CPPUNIT_ASSERT(aPositiveId.strip()==istrip);
	  CPPUNIT_ASSERT(aPositiveId.six()==ix);
	  CPPUNIT_ASSERT(aPositiveId.siy()==iy);
	  CPPUNIT_ASSERT(aPositiveId.plane()==1);
	  CPPUNIT_ASSERT(aPositiveId.zside()==1);
	}
	//ESDetId Plane 0 Zside -1 
	{
	  ESDetId aNegativeId(istrip,ix,iy,0,-1);
	  CPPUNIT_ASSERT(aNegativeId.strip()==istrip);
	  CPPUNIT_ASSERT(aNegativeId.six()==ix);
	  CPPUNIT_ASSERT(aNegativeId.siy()==iy);
	  CPPUNIT_ASSERT(aNegativeId.plane()==0);
	  CPPUNIT_ASSERT(aNegativeId.zside()==-1);
	}
	//ESDetId Plane 1 Zside -1 
	{
	  ESDetId aNegativeId(istrip,ix,iy,1,-1);
	  CPPUNIT_ASSERT(aNegativeId.strip()==istrip);
	  CPPUNIT_ASSERT(aNegativeId.six()==ix);
	  CPPUNIT_ASSERT(aNegativeId.siy()==iy);
	  CPPUNIT_ASSERT(aNegativeId.plane()==1);
	  CPPUNIT_ASSERT(aNegativeId.zside()==-1);
	}
      }
  
}


void testEcalDetId::testEcalTrigTowerDetId() {

  for (int ieta=EcalTrigTowerDetId::MIN_IETA;ieta<=EcalTrigTowerDetId::MAX_IETA;ieta++)
      for (int iphi=EcalTrigTowerDetId::MIN_IPHI;iphi<=EcalTrigTowerDetId::MAX_IPHI;iphi++)
	{
	  //EcalTrigTowerDetId Zside 1 
	  {
	    EcalTrigTowerDetId aPositiveId(ieta,iphi);
	    CPPUNIT_ASSERT(aPositiveId.ieta()==ieta);
	    CPPUNIT_ASSERT(aPositiveId.iphi()==iphi);
	    CPPUNIT_ASSERT(aPositiveId.zside()==1);
	    CPPUNIT_ASSERT(aPositiveId.ietaAbs()==ieta);
	  }
	  //EcalTrigTowerDetId Zside -1 
	  {
	    EcalTrigTowerDetId aNegativeId(-1*ieta,iphi);
	    CPPUNIT_ASSERT(aNegativeId.ieta()==-1*ieta);
	    CPPUNIT_ASSERT(aNegativeId.iphi()==iphi);
	    CPPUNIT_ASSERT(aNegativeId.zside()==-1);
	    CPPUNIT_ASSERT(aNegativeId.ietaAbs()==ieta);
	  }
	}

}
