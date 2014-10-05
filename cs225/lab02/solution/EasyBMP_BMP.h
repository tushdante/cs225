/*************************************************
*                                                *
*  EasyBMP Cross-Platform Windows Bitmap Library * 
*                                                *
*  Author: Paul Macklin                          *
*   email: macklin01@users.sourceforge.net       *
* support: http://easybmp.sourceforge.net        *
*                                                *
*          file: EasyBMP_VariousBMPutilities.h   *
*    date added: 05-02-2005                      *
* date modified: 09-13-2006                      *
*       version: 1.04                            *
*                                                *
*   License: BSD (revised/modified)              *
* Copyright: 2005-6 by the EasyBMP Project       * 
*                                                *
* description: Defines BMP class                 *
*                                                *
*                                                *
* Modified 9/06 by Bill Kinnersley for CS225     *
* Changes:                                       *
*   - improved "const correctness"               *
*   - implemented BMP::operator=()               *
*                                                *
*************************************************/

#ifndef _EasyBMP_BMP_h_
#define _EasyBMP_BMP_h_

bool SafeFread(char* buffer, int size, int number, FILE* fp);
bool EasyBMPcheckDataSize(void);

class BMP
{
private:

   int BitDepth;
   int Width;
   int Height;
   int XPelsPerMeter;
   int YPelsPerMeter;

   RGBApixel** Pixels;
   RGBApixel* Colors;

   ebmpBYTE* MetaData1;
   int SizeOfMetaData1;
   ebmpBYTE* MetaData2;
   int SizeOfMetaData2;
   
   bool Read32bitRow(ebmpBYTE* Buffer, int BufferSize, int Row);
   bool Read24bitRow(ebmpBYTE* Buffer, int BufferSize, int Row);   
   bool Read8bitRow(ebmpBYTE* Buffer, int BufferSize, int Row);  
   bool Read4bitRow(ebmpBYTE* Buffer, int BufferSize, int Row);  
   bool Read1bitRow(ebmpBYTE* Buffer, int BufferSize, int Row);
   
   bool Write32bitRow(ebmpBYTE* Buffer, int BufferSize, int Row) const;
   bool Write24bitRow(ebmpBYTE* Buffer, int BufferSize, int Row) const;   
   bool Write8bitRow(ebmpBYTE* Buffer, int BufferSize, int Row) const;  
   bool Write4bitRow(ebmpBYTE* Buffer, int BufferSize, int Row) const;  
   bool Write1bitRow(ebmpBYTE* Buffer, int BufferSize, int Row) const;
 
   ebmpBYTE FindClosestColor(RGBApixel const & input) const;

public: 

   int TellBitDepth(void) const;
   int TellWidth(void) const;
   int TellHeight(void) const;
   int TellNumberOfColors(void) const;
   void SetDPI(int HorizontalDPI, int VerticalDPI);
   int TellVerticalDPI(void) const;
   int TellHorizontalDPI(void) const;
  
   BMP();
   ~BMP();
   BMP(const BMP & other);
   RGBApixel* operator()(int i, int j);
   const RGBApixel* operator()(int i, int j) const;
   BMP const & operator=(BMP const & rhs);
 
   bool CreateStandardColorTable(void);
 
   bool SetSize(int NewWidth, int NewHeight);
   bool SetBitDepth(int NewDepth);
   bool WriteToFile(const char* FileName) const;
   bool ReadFromFile(const char* FileName);
 
   RGBApixel GetColor(int ColorNumber) const;
   bool SetColor(int ColorNumber, RGBApixel const & NewColor); 
};

#endif
