//=================================================================================================
/*!
//  \file src/mathtest/hermitianmatrix/DenseComplexTest.cpp
//  \brief Source file for the HermitianMatrix dense complex test
//
//  Copyright (C) 2013 Klaus Iglberger - All Rights Reserved
//
//  This file is part of the Blaze library. You can redistribute it and/or modify it under
//  the terms of the New (Revised) BSD License. Redistribution and use in source and binary
//  forms, with or without modification, are permitted provided that the following conditions
//  are met:
//
//  1. Redistributions of source code must retain the above copyright notice, this list of
//     conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright notice, this list
//     of conditions and the following disclaimer in the documentation and/or other materials
//     provided with the distribution.
//  3. Neither the names of the Blaze development group nor the names of its contributors
//     may be used to endorse or promote products derived from this software without specific
//     prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//  SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
//  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
//  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
//  DAMAGE.
*/
//=================================================================================================


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <cstdlib>
#include <iostream>
#include <blaze/math/CompressedMatrix.h>
#include <blaze/math/CustomMatrix.h>
#include <blaze/math/DenseColumn.h>
#include <blaze/math/DenseRow.h>
#include <blaze/math/DenseSubmatrix.h>
#include <blaze/math/HybridMatrix.h>
#include <blaze/math/StaticMatrix.h>
#include <blaze/math/StaticVector.h>
#include <blaze/util/policies/ArrayDelete.h>
#include <blaze/util/UniqueArray.h>
#include <blazetest/mathtest/hermitianmatrix/DenseComplexTest.h>


namespace blazetest {

namespace mathtest {

namespace hermitianmatrix {

//=================================================================================================
//
//  CONSTRUCTORS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Constructor for the HermitianMatrix dense test.
//
// \exception std::runtime_error Operation error detected.
*/
DenseComplexTest::DenseComplexTest()
{
   testConstructors();
   testAssignment();
   testAddAssign();
   testSubAssign();
   testMultAssign();
   testScaling();
   testFunctionCall();
   testIterator();
   testNonZeros();
   testReset();
   testClear();
   testResize();
   testExtend();
   testReserve();
   testTranspose();
   testCTranspose();
   testSwap();
   testIsDefault();
   testSubmatrix();
   testRow();
   testColumn();
}
//*************************************************************************************************




//=================================================================================================
//
//  TEST FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Test of the HermitianMatrix constructors.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of all constructors of the HermitianMatrix specialization.
// In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void DenseComplexTest::testConstructors()
{
   //=====================================================================================
   // Row-major default constructor
   //=====================================================================================

   // Default constructor (StaticMatrix)
   {
      test_ = "Row-major HermitianMatrix default constructor (StaticMatrix)";

      const blaze::HermitianMatrix< blaze::StaticMatrix<cplx,3UL,3UL,blaze::rowMajor> > herm;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkNonZeros( herm, 0UL );
   }

   // Default constructor (HybridMatrix)
   {
      test_ = "Row-major HermitianMatrix default constructor (HybridMatrix)";

      const blaze::HermitianMatrix< blaze::HybridMatrix<cplx,3UL,3UL,blaze::rowMajor> > herm;

      checkRows    ( herm, 0UL );
      checkColumns ( herm, 0UL );
      checkNonZeros( herm, 0UL );
   }

   // Default constructor (DynamicMatrix)
   {
      test_ = "Row-major HermitianMatrix default constructor (DynamicMatrix)";

      const HT herm;

      checkRows    ( herm, 0UL );
      checkColumns ( herm, 0UL );
      checkNonZeros( herm, 0UL );
   }


   //=====================================================================================
   // Row-major size constructor
   //=====================================================================================

   // Size constructor (HybridMatrix)
   {
      test_ = "Row-major HermitianMatrix size constructor (HybridMatrix)";

      const blaze::HermitianMatrix< blaze::HybridMatrix<cplx,3UL,3UL,blaze::rowMajor> > herm( 2UL );

      checkRows    ( herm, 2UL );
      checkColumns ( herm, 2UL );
      checkCapacity( herm, 4UL );
      checkNonZeros( herm, 0UL );
   }

   // Size constructor (DynamicMatrix)
   {
      test_ = "Row-major HermitianMatrix size constructor (DynamicMatrix)";

      const HT herm( 2UL );

      checkRows    ( herm, 2UL );
      checkColumns ( herm, 2UL );
      checkCapacity( herm, 4UL );
      checkNonZeros( herm, 0UL );
   }


   //=====================================================================================
   // Row-major custom matrix constructors
   //=====================================================================================

   // Custom matrix constructor (ElementType*, size_t)
   {
      test_ = "Row-major HermitianMatrix custom matrix constructor (ElementType*, size_t)";

      using blaze::unaligned;
      using blaze::unpadded;
      using blaze::rowMajor;

      typedef blaze::CustomMatrix<cplx,unaligned,unpadded,rowMajor>  UnalignedUnpadded;
      blaze::UniqueArray<cplx> array( new cplx[5UL] );
      array[1] = cplx(1, 0);
      array[2] = cplx(2, 1);
      array[3] = cplx(2,-1);
      array[4] = cplx(3, 0);
      const blaze::HermitianMatrix<UnalignedUnpadded> herm( array.get()+1UL, 2UL );

      checkRows    ( herm, 2UL );
      checkColumns ( herm, 2UL );
      checkCapacity( herm, 4UL );
      checkNonZeros( herm, 4UL );

      if( herm(0,0) != cplx(1, 0) || herm(0,1) != cplx(2,1) ||
          herm(1,0) != cplx(2,-1) || herm(1,1) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Construction failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (1, 0) (2,1) )\n( (2,-1) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Custom matrix constructor (ElementType*, size_t, size_t)
   {
      test_ = "Row-major HermitianMatrix custom matrix constructor (ElementType*, size_t, size_t)";

      using blaze::unaligned;
      using blaze::unpadded;
      using blaze::rowMajor;

      typedef blaze::CustomMatrix<cplx,unaligned,unpadded,rowMajor>  UnalignedUnpadded;
      blaze::UniqueArray<cplx> array( new cplx[11UL] );
      array[1] = cplx(1, 0);
      array[2] = cplx(2, 1);
      array[6] = cplx(2,-1);
      array[7] = cplx(3, 0);
      const blaze::HermitianMatrix<UnalignedUnpadded> herm( array.get()+1UL, 2UL, 5UL );

      checkRows    ( herm, 2UL );
      checkColumns ( herm, 2UL );
      checkCapacity( herm, 4UL );
      checkNonZeros( herm, 4UL );

      if( herm(0,0) != cplx(1, 0) || herm(0,1) != cplx(2,1) ||
          herm(1,0) != cplx(2,-1) || herm(1,1) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Construction failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (1, 0) (2,1) )\n( (2,-1) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Custom matrix constructor (ElementType*, size_t, Deleter)
   {
      test_ = "Row-major HermitianMatrix custom matrix constructor (ElementType*, size_t, Deleter)";

      using blaze::unaligned;
      using blaze::unpadded;
      using blaze::rowMajor;

      typedef blaze::CustomMatrix<cplx,unaligned,unpadded,rowMajor>  UnalignedUnpadded;
      blaze::UniqueArray<cplx> array( new cplx[4UL] );
      array[0] = cplx(1, 0);
      array[1] = cplx(2, 1);
      array[2] = cplx(2,-1);
      array[3] = cplx(3, 0);
      const blaze::HermitianMatrix<UnalignedUnpadded> herm( array.release(), 2UL, blaze::ArrayDelete() );

      checkRows    ( herm, 2UL );
      checkColumns ( herm, 2UL );
      checkCapacity( herm, 4UL );
      checkNonZeros( herm, 4UL );

      if( herm(0,0) != cplx(1, 0) || herm(0,1) != cplx(2,1) ||
          herm(1,0) != cplx(2,-1) || herm(1,1) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Construction failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (1, 0) (2,1) )\n( (2,-1) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Custom matrix constructor (ElementType*, size_t, size_t, Deleter)
   {
      test_ = "Row-major HermitianMatrix custom matrix constructor (ElementType*, size_t, size_t, Deleter)";

      using blaze::unaligned;
      using blaze::unpadded;
      using blaze::rowMajor;

      typedef blaze::CustomMatrix<cplx,unaligned,unpadded,rowMajor>  UnalignedUnpadded;
      blaze::UniqueArray<cplx> array( new cplx[10UL] );
      array[0] = cplx(1, 0);
      array[1] = cplx(2, 1);
      array[5] = cplx(2,-1);
      array[6] = cplx(3, 0);
      const blaze::HermitianMatrix<UnalignedUnpadded> herm( array.release(), 2UL, 5UL, blaze::ArrayDelete() );

      checkRows    ( herm, 2UL );
      checkColumns ( herm, 2UL );
      checkCapacity( herm, 4UL );
      checkNonZeros( herm, 4UL );

      if( herm(0,0) != cplx(1, 0) || herm(0,1) != cplx(2,1) ||
          herm(1,0) != cplx(2,-1) || herm(1,1) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Construction failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (1, 0) (2,1) )\n( (2,-1) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major copy constructor
   //=====================================================================================

   // Copy constructor (0x0)
   {
      test_ = "Row-major HermitianMatrix copy constructor (0x0)";

      const HT herm1;
      const HT herm2( herm1 );

      checkRows    ( herm2, 0UL );
      checkColumns ( herm2, 0UL );
      checkNonZeros( herm2, 0UL );
   }

   // Copy constructor (3x3)
   {
      test_ = "Row-major HermitianMatrix copy constructor (3x3)";

      HT herm1( 3UL );
      herm1(0,0) = cplx( 1, 0);
      herm1(0,1) = cplx(-4,-1);
      herm1(0,2) = cplx( 7, 3);
      herm1(1,1) = cplx( 2, 0);
      herm1(2,2) = cplx( 3, 0);

      const HT herm2( herm1 );

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-4,-1) || herm2(0,2) != cplx(7,3) ||
          herm2(1,0) != cplx(-4, 1) || herm2(1,1) != cplx( 2, 0) || herm2(1,2) != cplx(0,0) ||
          herm2(2,0) != cplx( 7,-3) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Construction failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) (7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (0,0) )\n"
                                     "( ( 7,-3) ( 0, 0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major conversion constructor
   //=====================================================================================

   // Conversion constructor (0x0)
   {
      test_ = "Row-major HermitianMatrix conversion constructor (0x0)";

      const blaze::DynamicMatrix<cplx,blaze::rowMajor> mat;
      const HT herm( mat );

      checkRows    ( herm, 0UL );
      checkColumns ( herm, 0UL );
      checkNonZeros( herm, 0UL );
   }

   // Conversion constructor (Hermitian)
   {
      test_ = "Row-major HermitianMatrix conversion constructor (Hermitian)";

      blaze::DynamicMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 0);
      mat(1,2) = cplx( 0, 0);
      mat(2,0) = cplx( 7,-3);
      mat(2,1) = cplx( 0, 0);
      mat(2,2) = cplx( 3, 0);

      const HT herm( mat );

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-4,-1) || herm(0,2) != cplx(7,3) ||
          herm(1,0) != cplx(-4, 1) || herm(1,1) != cplx( 2, 0) || herm(1,2) != cplx(0,0) ||
          herm(2,0) != cplx( 7,-3) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Construction failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) (7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (0,0) )\n"
                                     "( ( 7,-3) ( 0, 0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Conversion constructor (invalid diagonal)
   {
      test_ = "Row-major HermitianMatrix conversion constructor (invalid diagonal)";

      blaze::DynamicMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 1);
      mat(1,2) = cplx( 0, 0);
      mat(2,0) = cplx( 7,-3);
      mat(2,1) = cplx( 0, 0);
      mat(2,2) = cplx( 3, 0);

      try {
         const HT herm( mat );

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Setup of non-Hermitian HermitianMatrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Conversion constructor (invalid pair)
   {
      test_ = "Row-major HermitianMatrix conversion constructor (invalid pair)";

      blaze::DynamicMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 0);
      mat(1,2) = cplx( 0, 0);
      mat(2,0) = cplx( 7, 3);
      mat(2,1) = cplx( 0, 0);
      mat(2,2) = cplx( 3, 0);

      try {
         const HT herm( mat );

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Setup of non-Hermitian HermitianMatrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Conversion constructor (HermitianMatrix)
   {
      test_ = "Row-major HermitianMatrix conversion constructor (HermitianMatrix)";

      blaze::HermitianMatrix< blaze::StaticMatrix<cplx,3UL,3UL,blaze::rowMajor> > herm1;
      herm1(0,0) = cplx( 1, 0);
      herm1(0,1) = cplx(-4,-1);
      herm1(0,2) = cplx( 7, 3);
      herm1(1,1) = cplx( 2, 0);
      herm1(2,2) = cplx( 3, 0);

      const HT herm2( herm1 );

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-4,-1) || herm2(0,2) != cplx(7,3) ||
          herm2(1,0) != cplx(-4, 1) || herm2(1,1) != cplx( 2, 0) || herm2(1,2) != cplx(0,0) ||
          herm2(2,0) != cplx( 7,-3) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Construction failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) (7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (0,0) )\n"
                                     "( ( 7,-3) ( 0, 0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major default constructor
   //=====================================================================================

   // Default constructor (StaticMatrix)
   {
      test_ = "Column-major HermitianMatrix default constructor (StaticMatrix)";

      const blaze::HermitianMatrix< blaze::StaticMatrix<cplx,3UL,3UL,blaze::columnMajor> > herm;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkNonZeros( herm, 0UL );
   }

   // Default constructor (HybridMatrix)
   {
      test_ = "Column-major HermitianMatrix default constructor (HybridMatrix)";

      const blaze::HermitianMatrix< blaze::HybridMatrix<cplx,3UL,3UL,blaze::columnMajor> > herm;

      checkRows    ( herm, 0UL );
      checkColumns ( herm, 0UL );
      checkNonZeros( herm, 0UL );
   }

   // Default constructor (DynamicMatrix)
   {
      test_ = "Column-major HermitianMatrix default constructor (DynamicMatrix)";

      const OHT herm;

      checkRows    ( herm, 0UL );
      checkColumns ( herm, 0UL );
      checkNonZeros( herm, 0UL );
   }


   //=====================================================================================
   // Column-major size constructor
   //=====================================================================================

   // Size constructor (HybridMatrix)
   {
      test_ = "Column-major HermitianMatrix size constructor (HybridMatrix)";

      const blaze::HermitianMatrix< blaze::HybridMatrix<cplx,3UL,3UL,blaze::columnMajor> > herm( 2UL );

      checkRows    ( herm, 2UL );
      checkColumns ( herm, 2UL );
      checkCapacity( herm, 4UL );
      checkNonZeros( herm, 0UL );
   }

   // Size constructor (DynamicMatrix)
   {
      test_ = "Column-major HermitianMatrix size constructor (DynamicMatrix)";

      const OHT herm( 2UL );

      checkRows    ( herm, 2UL );
      checkColumns ( herm, 2UL );
      checkCapacity( herm, 4UL );
      checkNonZeros( herm, 0UL );
   }


   //=====================================================================================
   // Column-major custom matrix constructors
   //=====================================================================================

   // Custom matrix constructor (ElementType*, size_t)
   {
      test_ = "Column-major HermitianMatrix custom matrix constructor (ElementType*, size_t)";

      using blaze::unaligned;
      using blaze::unpadded;
      using blaze::columnMajor;

      typedef blaze::CustomMatrix<cplx,unaligned,unpadded,columnMajor>  UnalignedUnpadded;
      blaze::UniqueArray<cplx> array( new cplx[5UL] );
      array[1] = cplx(1, 0);
      array[2] = cplx(2,-1);
      array[3] = cplx(2, 1);
      array[4] = cplx(3, 0);
      const blaze::HermitianMatrix<UnalignedUnpadded> herm( array.get()+1UL, 2UL );

      checkRows    ( herm, 2UL );
      checkColumns ( herm, 2UL );
      checkCapacity( herm, 4UL );
      checkNonZeros( herm, 4UL );

      if( herm(0,0) != cplx(1, 0) || herm(0,1) != cplx(2,1) ||
          herm(1,0) != cplx(2,-1) || herm(1,1) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Construction failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (1, 0) (2,1) )\n( (2,-1) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Custom matrix constructor (ElementType*, size_t, size_t)
   {
      test_ = "Column-major HermitianMatrix custom matrix constructor (ElementType*, size_t, size_t)";

      using blaze::unaligned;
      using blaze::unpadded;
      using blaze::columnMajor;

      typedef blaze::CustomMatrix<cplx,unaligned,unpadded,columnMajor>  UnalignedUnpadded;
      blaze::UniqueArray<cplx> array( new cplx[11UL] );
      array[1] = cplx(1, 0);
      array[2] = cplx(2,-1);
      array[6] = cplx(2, 1);
      array[7] = cplx(3, 0);
      const blaze::HermitianMatrix<UnalignedUnpadded> herm( array.get()+1UL, 2UL, 5UL );

      checkRows    ( herm, 2UL );
      checkColumns ( herm, 2UL );
      checkCapacity( herm, 4UL );
      checkNonZeros( herm, 4UL );

      if( herm(0,0) != cplx(1, 0) || herm(0,1) != cplx(2,1) ||
          herm(1,0) != cplx(2,-1) || herm(1,1) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Construction failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (1, 0) (2,1) )\n( (2,-1) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Custom matrix constructor (ElementType*, size_t, Deleter)
   {
      test_ = "Column-major HermitianMatrix custom matrix constructor (ElementType*, size_t, Deleter)";

      using blaze::unaligned;
      using blaze::unpadded;
      using blaze::columnMajor;

      typedef blaze::CustomMatrix<cplx,unaligned,unpadded,columnMajor>  UnalignedUnpadded;
      blaze::UniqueArray<cplx> array( new cplx[4UL] );
      array[0] = cplx(1, 0);
      array[1] = cplx(2,-1);
      array[2] = cplx(2, 1);
      array[3] = cplx(3, 0);
      const blaze::HermitianMatrix<UnalignedUnpadded> herm( array.release(), 2UL, blaze::ArrayDelete() );

      checkRows    ( herm, 2UL );
      checkColumns ( herm, 2UL );
      checkCapacity( herm, 4UL );
      checkNonZeros( herm, 4UL );

      if( herm(0,0) != cplx(1, 0) || herm(0,1) != cplx(2,1) ||
          herm(1,0) != cplx(2,-1) || herm(1,1) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Construction failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (1, 0) (2,1) )\n( (2,-1) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Custom matrix constructor (ElementType*, size_t, size_t, Deleter)
   {
      test_ = "Column-major HermitianMatrix custom matrix constructor (ElementType*, size_t, size_t, Deleter)";

      using blaze::unaligned;
      using blaze::unpadded;
      using blaze::columnMajor;

      typedef blaze::CustomMatrix<cplx,unaligned,unpadded,columnMajor>  UnalignedUnpadded;
      blaze::UniqueArray<cplx> array( new cplx[10UL] );
      array[0] = cplx(1, 0);
      array[1] = cplx(2,-1);
      array[5] = cplx(2, 1);
      array[6] = cplx(3, 0);
      const blaze::HermitianMatrix<UnalignedUnpadded> herm( array.release(), 2UL, 5UL, blaze::ArrayDelete() );

      checkRows    ( herm, 2UL );
      checkColumns ( herm, 2UL );
      checkCapacity( herm, 4UL );
      checkNonZeros( herm, 4UL );

      if( herm(0,0) != cplx(1, 0) || herm(0,1) != cplx(2,1) ||
          herm(1,0) != cplx(2,-1) || herm(1,1) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Construction failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (1, 0) (2,1) )\n( (2,-1) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major copy constructor
   //=====================================================================================

   // Copy constructor (0x0)
   {
      test_ = "Column-major HermitianMatrix copy constructor (0x0)";

      const OHT herm1;
      const OHT herm2( herm1 );

      checkRows    ( herm2, 0UL );
      checkColumns ( herm2, 0UL );
      checkNonZeros( herm2, 0UL );
   }

   // Copy constructor (3x3)
   {
      test_ = "Column-major HermitianMatrix copy constructor (3x3)";

      OHT herm1( 3UL );
      herm1(0,0) = cplx( 1, 0);
      herm1(0,1) = cplx(-4,-1);
      herm1(0,2) = cplx( 7, 3);
      herm1(1,1) = cplx( 2, 0);
      herm1(2,2) = cplx( 3, 0);

      const OHT herm2( herm1 );

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-4,-1) || herm2(0,2) != cplx(7,3) ||
          herm2(1,0) != cplx(-4, 1) || herm2(1,1) != cplx( 2, 0) || herm2(1,2) != cplx(0,0) ||
          herm2(2,0) != cplx( 7,-3) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Construction failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) (7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (0,0) )\n"
                                     "( ( 7,-3) ( 0, 0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major conversion constructor
   //=====================================================================================

   // Conversion constructor (0x0)
   {
      test_ = "Column-major HermitianMatrix conversion constructor (0x0)";

      const blaze::DynamicMatrix<cplx,blaze::columnMajor> mat;
      const OHT herm( mat );

      checkRows    ( herm, 0UL );
      checkColumns ( herm, 0UL );
      checkNonZeros( herm, 0UL );
   }

   // Conversion constructor (Hermitian)
   {
      test_ = "Column-major HermitianMatrix conversion constructor (Hermitian)";

      blaze::DynamicMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 0);
      mat(1,2) = cplx( 0, 0);
      mat(2,0) = cplx( 7,-3);
      mat(2,1) = cplx( 0, 0);
      mat(2,2) = cplx( 3, 0);

      const OHT herm( mat );

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-4,-1) || herm(0,2) != cplx(7,3) ||
          herm(1,0) != cplx(-4, 1) || herm(1,1) != cplx( 2, 0) || herm(1,2) != cplx(0,0) ||
          herm(2,0) != cplx( 7,-3) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Construction failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) (7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (0,0) )\n"
                                     "( ( 7,-3) ( 0, 0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Conversion constructor (invalid diagonal)
   {
      test_ = "Column-major HermitianMatrix conversion constructor (invalid diagonal)";

      blaze::DynamicMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 1);
      mat(1,2) = cplx( 0, 0);
      mat(2,0) = cplx( 7,-3);
      mat(2,1) = cplx( 0, 0);
      mat(2,2) = cplx( 3, 0);

      try {
         const OHT herm( mat );

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Setup of non-Hermitian HermitianMatrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Conversion constructor (invalid pair)
   {
      test_ = "Column-major HermitianMatrix conversion constructor (invalid pair)";

      blaze::DynamicMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 0);
      mat(1,2) = cplx( 0, 0);
      mat(2,0) = cplx( 7, 3);
      mat(2,1) = cplx( 0, 0);
      mat(2,2) = cplx( 3, 0);

      try {
         const OHT herm( mat );

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Setup of non-Hermitian HermitianMatrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Conversion constructor (HermitianMatrix)
   {
      test_ = "Column-major HermitianMatrix conversion constructor (HermitianMatrix)";

      blaze::HermitianMatrix< blaze::StaticMatrix<cplx,3UL,3UL,blaze::columnMajor> > herm1;
      herm1(0,0) = cplx( 1, 0);
      herm1(0,1) = cplx(-4,-1);
      herm1(0,2) = cplx( 7, 3);
      herm1(1,1) = cplx( 2, 0);
      herm1(2,2) = cplx( 3, 0);

      const OHT herm2( herm1 );

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-4,-1) || herm2(0,2) != cplx(7,3) ||
          herm2(1,0) != cplx(-4, 1) || herm2(1,1) != cplx( 2, 0) || herm2(1,2) != cplx(0,0) ||
          herm2(2,0) != cplx( 7,-3) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Construction failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) (7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (0,0) )\n"
                                     "( ( 7,-3) ( 0, 0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the HermitianMatrix assignment operators.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of all assignment operators of the HermitianMatrix specialization.
// In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void DenseComplexTest::testAssignment()
{
   //=====================================================================================
   // Row-major copy assignment
   //=====================================================================================

   // Copy assignment (0x0)
   {
      test_ = "Row-major HermitianMatrix copy assignment (0x0)";

      HT herm1, herm2;

      herm2 = herm1;

      checkRows    ( herm2, 0UL );
      checkColumns ( herm2, 0UL );
      checkNonZeros( herm2, 0UL );
   }

   // Copy assignment (3x3)
   {
      test_ = "Row-major HermitianMatrix copy assignment (3x3)";

      HT herm1( 3UL );
      herm1(0,0) = cplx( 1, 0);
      herm1(0,1) = cplx(-4,-1);
      herm1(0,2) = cplx( 7, 3);
      herm1(1,1) = cplx( 2, 0);
      herm1(2,2) = cplx( 3, 0);

      HT herm2;
      herm2 = herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkNonZeros( herm2, 7UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-4,-1) || herm2(0,2) != cplx(7,3) ||
          herm2(1,0) != cplx(-4, 1) || herm2(1,1) != cplx( 2, 0) || herm2(1,2) != cplx(0,0) ||
          herm2(2,0) != cplx( 7,-3) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) (7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (0,0) )\n"
                                     "( ( 7,-3) ( 0, 0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major dense matrix assignment
   //=====================================================================================

   // Conversion assignment (0x0)
   {
      test_ = "Row-major HermitianMatrix dense matrix assignment (0x0)";

      const blaze::DynamicMatrix<cplx,blaze::rowMajor> mat;

      HT herm;
      herm = mat;

      checkRows    ( herm, 0UL );
      checkColumns ( herm, 0UL );
      checkNonZeros( herm, 0UL );
   }

   // Row-major/row-major dense matrix assignment (Hermitian)
   {
      test_ = "Row-major/row-major HermitianMatrix dense matrix assignment (Hermitian)";

      blaze::DynamicMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 0);
      mat(1,2) = cplx( 0, 0);
      mat(2,0) = cplx( 7,-3);
      mat(2,1) = cplx( 0, 0);
      mat(2,2) = cplx( 3, 0);

      HT herm;
      herm = mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkNonZeros( herm, 7UL );

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-4,-1) || herm(0,2) != cplx(7,3) ||
          herm(1,0) != cplx(-4, 1) || herm(1,1) != cplx( 2, 0) || herm(1,2) != cplx(0,0) ||
          herm(2,0) != cplx( 7,-3) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) (7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (0,0) )\n"
                                     "( ( 7,-3) ( 0, 0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Row-major/column-major dense matrix assignment (Hermitian)
   {
      test_ = "Row-major/column-major HermitianMatrix dense matrix assignment (Hermitian)";

      blaze::DynamicMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 0);
      mat(1,2) = cplx( 0, 0);
      mat(2,0) = cplx( 7,-3);
      mat(2,1) = cplx( 0, 0);
      mat(2,2) = cplx( 3, 0);

      HT herm;
      herm = mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkNonZeros( herm, 7UL );

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-4,-1) || herm(0,2) != cplx(7,3) ||
          herm(1,0) != cplx(-4, 1) || herm(1,1) != cplx( 2, 0) || herm(1,2) != cplx(0,0) ||
          herm(2,0) != cplx( 7,-3) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) (7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (0,0) )\n"
                                     "( ( 7,-3) ( 0, 0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Row-major/row-major dense matrix assignment (invalid diagonal)
   {
      test_ = "Row-major/row-major HermitianMatrix dense matrix assignment (invalid diagonal)";

      blaze::DynamicMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 1);
      mat(1,2) = cplx( 0, 0);
      mat(2,0) = cplx( 7,-3);
      mat(2,1) = cplx( 0, 0);
      mat(2,2) = cplx( 3, 0);

      try {
         HT herm;
         herm = mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/column-major dense matrix assignment (invalid diagonal)
   {
      test_ = "Row-major/column-major HermitianMatrix dense matrix assignment (invalid diagonal)";

      blaze::DynamicMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 1);
      mat(1,2) = cplx( 0, 0);
      mat(2,0) = cplx( 7,-3);
      mat(2,1) = cplx( 0, 0);
      mat(2,2) = cplx( 3, 0);

      try {
         HT herm;
         herm = mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/row-major dense matrix assignment (invalid pair)
   {
      test_ = "Row-major/row-major HermitianMatrix dense matrix assignment (invalid pair)";

      blaze::DynamicMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 0);
      mat(1,2) = cplx( 0, 0);
      mat(2,0) = cplx( 7, 3);
      mat(2,1) = cplx( 0, 0);
      mat(2,2) = cplx( 3, 0);

      try {
         HT herm;
         herm = mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/column-major dense matrix assignment (invalid pair)
   {
      test_ = "Row-major/column-major HermitianMatrix dense matrix assignment (invalid pair)";

      blaze::DynamicMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 0);
      mat(1,2) = cplx( 0, 0);
      mat(2,0) = cplx( 7, 3);
      mat(2,1) = cplx( 0, 0);
      mat(2,2) = cplx( 3, 0);

      try {
         HT herm;
         herm = mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/row-major dense matrix assignment (HermitianMatrix)
   {
      test_ = "Row-major/row-major HermitianMatrix dense matrix assignment (HermitianMatrix)";

      blaze::HermitianMatrix< blaze::StaticMatrix<cplx,3UL,3UL,blaze::rowMajor> > herm1;
      herm1(0,0) = cplx( 1, 0);
      herm1(0,1) = cplx(-4,-1);
      herm1(0,2) = cplx( 7, 3);
      herm1(1,1) = cplx( 2, 0);
      herm1(2,2) = cplx( 3, 0);

      HT herm2;
      herm2 = herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkNonZeros( herm2, 7UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-4,-1) || herm2(0,2) != cplx(7,3) ||
          herm2(1,0) != cplx(-4, 1) || herm2(1,1) != cplx( 2, 0) || herm2(1,2) != cplx(0,0) ||
          herm2(2,0) != cplx( 7,-3) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) (7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (0,0) )\n"
                                     "( ( 7,-3) ( 0, 0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Row-major/column-major dense matrix assignment (HermitianMatrix)
   {
      test_ = "Row-major/column-major HermitianMatrix dense matrix assignment (HermitianMatrix)";

      blaze::HermitianMatrix< blaze::StaticMatrix<cplx,3UL,3UL,blaze::columnMajor> > herm1;
      herm1(0,0) = cplx( 1, 0);
      herm1(0,1) = cplx(-4,-1);
      herm1(0,2) = cplx( 7, 3);
      herm1(1,1) = cplx( 2, 0);
      herm1(2,2) = cplx( 3, 0);

      HT herm2;
      herm2 = herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkNonZeros( herm2, 7UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-4,-1) || herm2(0,2) != cplx(7,3) ||
          herm2(1,0) != cplx(-4, 1) || herm2(1,1) != cplx( 2, 0) || herm2(1,2) != cplx(0,0) ||
          herm2(2,0) != cplx( 7,-3) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) (7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (0,0) )\n"
                                     "( ( 7,-3) ( 0, 0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major sparse matrix assignment
   //=====================================================================================

   // Conversion assignment (0x0)
   {
      test_ = "Row-major HermitianMatrix sparse matrix assignment (0x0)";

      const blaze::CompressedMatrix<cplx,blaze::rowMajor> mat;

      HT herm;
      herm = mat;

      checkRows    ( herm, 0UL );
      checkColumns ( herm, 0UL );
      checkNonZeros( herm, 0UL );
   }

   // Row-major/row-major sparse matrix assignment (Hermitian)
   {
      test_ = "Row-major/row-major HermitianMatrix sparse matrix assignment (Hermitian)";

      blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 8UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 0);
      mat(2,0) = cplx( 7,-3);
      mat(2,2) = cplx( 3, 0);
      mat.insert( 1UL, 2UL, cplx(0,0) );

      HT herm;
      herm = mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkNonZeros( herm, 7UL );

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-4,-1) || herm(0,2) != cplx(7,3) ||
          herm(1,0) != cplx(-4, 1) || herm(1,1) != cplx( 2, 0) || herm(1,2) != cplx(0,0) ||
          herm(2,0) != cplx( 7,-3) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) (7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (0,0) )\n"
                                     "( ( 7,-3) ( 0, 0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Row-major/column-major sparse matrix assignment (Hermitian)
   {
      test_ = "Row-major/column-major HermitianMatrix sparse matrix assignment (Hermitian)";

      blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 8UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 0);
      mat(2,0) = cplx( 7,-3);
      mat(2,2) = cplx( 3, 0);
      mat.insert( 1UL, 2UL, cplx(0,0) );

      HT herm;
      herm = mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkNonZeros( herm, 7UL );

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-4,-1) || herm(0,2) != cplx(7,3) ||
          herm(1,0) != cplx(-4, 1) || herm(1,1) != cplx( 2, 0) || herm(1,2) != cplx(0,0) ||
          herm(2,0) != cplx( 7,-3) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) (7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (0,0) )\n"
                                     "( ( 7,-3) ( 0, 0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Row-major/row-major sparse matrix assignment (invalid diagonal)
   {
      test_ = "Row-major/row-major HermitianMatrix sparse matrix assignment (invalid diagonal)";

      blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 7UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 1);
      mat(2,0) = cplx( 7,-3);
      mat(2,2) = cplx( 3, 0);

      try {
         HT herm;
         herm = mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/column-major sparse matrix assignment (invalid diagonal)
   {
      test_ = "Row-major/column-major HermitianMatrix sparse matrix assignment (invalid diagonal)";

      blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 7UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 1);
      mat(2,0) = cplx( 7,-3);
      mat(2,2) = cplx( 3, 0);

      try {
         HT herm;
         herm = mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/row-major sparse matrix assignment (invalid pair)
   {
      test_ = "Row-major/row-major HermitianMatrix sparse matrix assignment (invalid pair)";

      blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 7UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 0);
      mat(2,0) = cplx( 7, 3);
      mat(2,2) = cplx( 3, 0);

      try {
         HT herm;
         herm = mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/column-major sparse matrix assignment (invalid pair)
   {
      test_ = "Row-major/column-major HermitianMatrix sparse matrix assignment (invalid pair)";

      blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 7UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 0);
      mat(2,0) = cplx( 7, 3);
      mat(2,2) = cplx( 3, 0);

      try {
         HT herm;
         herm = mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/row-major sparse matrix assignment (HermitianMatrix)
   {
      test_ = "Row-major/row-major HermitianMatrix sparse matrix assignment (HermitianMatrix)";

      blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > herm1( 3UL, 7UL );
      herm1(0,0) = cplx( 1, 0);
      herm1(0,1) = cplx(-4,-1);
      herm1(0,2) = cplx( 7, 3);
      herm1(1,1) = cplx( 2, 0);
      herm1(2,2) = cplx( 3, 0);

      HT herm2;
      herm2 = herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkNonZeros( herm2, 7UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-4,-1) || herm2(0,2) != cplx(7,3) ||
          herm2(1,0) != cplx(-4, 1) || herm2(1,1) != cplx( 2, 0) || herm2(1,2) != cplx(0,0) ||
          herm2(2,0) != cplx( 7,-3) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) (7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (0,0) )\n"
                                     "( ( 7,-3) ( 0, 0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Row-major/column-major sparse matrix assignment (HermitianMatrix)
   {
      test_ = "Row-major/column-major HermitianMatrix sparse matrix assignment (HermitianMatrix)";

      blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > herm1( 3UL, 7UL );
      herm1(0,0) = cplx( 1, 0);
      herm1(0,1) = cplx(-4,-1);
      herm1(0,2) = cplx( 7, 3);
      herm1(1,1) = cplx( 2, 0);
      herm1(2,2) = cplx( 3, 0);

      HT herm2;
      herm2 = herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkNonZeros( herm2, 7UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-4,-1) || herm2(0,2) != cplx(7,3) ||
          herm2(1,0) != cplx(-4, 1) || herm2(1,1) != cplx( 2, 0) || herm2(1,2) != cplx(0,0) ||
          herm2(2,0) != cplx( 7,-3) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) (7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (0,0) )\n"
                                     "( ( 7,-3) ( 0, 0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major copy assignment
   //=====================================================================================

   // Copy assignment (0x0)
   {
      test_ = "Column-major HermitianMatrix copy assignment (0x0)";

      OHT herm1, herm2;

      herm2 = herm1;

      checkRows    ( herm2, 0UL );
      checkColumns ( herm2, 0UL );
      checkNonZeros( herm2, 0UL );
   }

   // Copy assignment (3x3)
   {
      test_ = "Column-major HermitianMatrix copy assignment (3x3)";

      OHT herm1( 3UL );
      herm1(0,0) = cplx( 1, 0);
      herm1(0,1) = cplx(-4,-1);
      herm1(0,2) = cplx( 7, 3);
      herm1(1,1) = cplx( 2, 0);
      herm1(2,2) = cplx( 3, 0);

      OHT herm2;
      herm2 = herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkNonZeros( herm2, 7UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-4,-1) || herm2(0,2) != cplx(7,3) ||
          herm2(1,0) != cplx(-4, 1) || herm2(1,1) != cplx( 2, 0) || herm2(1,2) != cplx(0,0) ||
          herm2(2,0) != cplx( 7,-3) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) (7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (0,0) )\n"
                                     "( ( 7,-3) ( 0, 0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major dense matrix assignment
   //=====================================================================================

   // Conversion assignment (0x0)
   {
      test_ = "Column-major HermitianMatrix dense matrix assignment (0x0)";

      const blaze::DynamicMatrix<cplx,blaze::rowMajor> mat;

      OHT herm;
      herm = mat;

      checkRows    ( herm, 0UL );
      checkColumns ( herm, 0UL );
      checkNonZeros( herm, 0UL );
   }

   // Column-major/row-major dense matrix assignment (Hermitian)
   {
      test_ = "Column-major/row-major HermitianMatrix dense matrix assignment (Hermitian)";

      blaze::DynamicMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 0);
      mat(1,2) = cplx( 0, 0);
      mat(2,0) = cplx( 7,-3);
      mat(2,1) = cplx( 0, 0);
      mat(2,2) = cplx( 3, 0);

      OHT herm;
      herm = mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkNonZeros( herm, 7UL );

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-4,-1) || herm(0,2) != cplx(7,3) ||
          herm(1,0) != cplx(-4, 1) || herm(1,1) != cplx( 2, 0) || herm(1,2) != cplx(0,0) ||
          herm(2,0) != cplx( 7,-3) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) (7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (0,0) )\n"
                                     "( ( 7,-3) ( 0, 0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Column-major/column-major dense matrix assignment (Hermitian)
   {
      test_ = "Column-major/column-major HermitianMatrix dense matrix assignment (Hermitian)";

      blaze::DynamicMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 0);
      mat(1,2) = cplx( 0, 0);
      mat(2,0) = cplx( 7,-3);
      mat(2,1) = cplx( 0, 0);
      mat(2,2) = cplx( 3, 0);

      OHT herm;
      herm = mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkNonZeros( herm, 7UL );

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-4,-1) || herm(0,2) != cplx(7,3) ||
          herm(1,0) != cplx(-4, 1) || herm(1,1) != cplx( 2, 0) || herm(1,2) != cplx(0,0) ||
          herm(2,0) != cplx( 7,-3) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) (7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (0,0) )\n"
                                     "( ( 7,-3) ( 0, 0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Column-major/row-major dense matrix assignment (invalid diagonal)
   {
      test_ = "Column-major/row-major HermitianMatrix dense matrix assignment (invalid diagonal)";

      blaze::DynamicMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 1);
      mat(1,2) = cplx( 0, 0);
      mat(2,0) = cplx( 7,-3);
      mat(2,1) = cplx( 0, 0);
      mat(2,2) = cplx( 3, 0);

      try {
         OHT herm;
         herm = mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/column-major dense matrix assignment (invalid diagonal)
   {
      test_ = "Column-major/column-major HermitianMatrix dense matrix assignment (invalid diagonal)";

      blaze::DynamicMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 1);
      mat(1,2) = cplx( 0, 0);
      mat(2,0) = cplx( 7,-3);
      mat(2,1) = cplx( 0, 0);
      mat(2,2) = cplx( 3, 0);

      try {
         OHT herm;
         herm = mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/row-major dense matrix assignment (invalid pair)
   {
      test_ = "Column-major/row-major HermitianMatrix dense matrix assignment (invalid pair)";

      blaze::DynamicMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 0);
      mat(1,2) = cplx( 0, 0);
      mat(2,0) = cplx( 7, 3);
      mat(2,1) = cplx( 0, 0);
      mat(2,2) = cplx( 3, 0);

      try {
         OHT herm;
         herm = mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/column-major dense matrix assignment (invalid pair)
   {
      test_ = "Column-major/column-major HermitianMatrix dense matrix assignment (invalid pair)";

      blaze::DynamicMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 0);
      mat(1,2) = cplx( 0, 0);
      mat(2,0) = cplx( 7, 3);
      mat(2,1) = cplx( 0, 0);
      mat(2,2) = cplx( 3, 0);

      try {
         OHT herm;
         herm = mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/row-major dense matrix assignment (HermitianMatrix)
   {
      test_ = "Column-major/row-major HermitianMatrix dense matrix assignment (HermitianMatrix)";

      blaze::HermitianMatrix< blaze::StaticMatrix<cplx,3UL,3UL,blaze::rowMajor> > herm1;
      herm1(0,0) = cplx( 1, 0);
      herm1(0,1) = cplx(-4,-1);
      herm1(0,2) = cplx( 7, 3);
      herm1(1,1) = cplx( 2, 0);
      herm1(2,2) = cplx( 3, 0);

      OHT herm2;
      herm2 = herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkNonZeros( herm2, 7UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-4,-1) || herm2(0,2) != cplx(7,3) ||
          herm2(1,0) != cplx(-4, 1) || herm2(1,1) != cplx( 2, 0) || herm2(1,2) != cplx(0,0) ||
          herm2(2,0) != cplx( 7,-3) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) (7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (0,0) )\n"
                                     "( ( 7,-3) ( 0, 0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Column-major/column-major dense matrix assignment (HermitianMatrix)
   {
      test_ = "Column-major/column-major HermitianMatrix dense matrix assignment (HermitianMatrix)";

      blaze::HermitianMatrix< blaze::StaticMatrix<cplx,3UL,3UL,blaze::columnMajor> > herm1;
      herm1(0,0) = cplx( 1, 0);
      herm1(0,1) = cplx(-4,-1);
      herm1(0,2) = cplx( 7, 3);
      herm1(1,1) = cplx( 2, 0);
      herm1(2,2) = cplx( 3, 0);

      OHT herm2;
      herm2 = herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkNonZeros( herm2, 7UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-4,-1) || herm2(0,2) != cplx(7,3) ||
          herm2(1,0) != cplx(-4, 1) || herm2(1,1) != cplx( 2, 0) || herm2(1,2) != cplx(0,0) ||
          herm2(2,0) != cplx( 7,-3) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) (7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (0,0) )\n"
                                     "( ( 7,-3) ( 0, 0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major sparse matrix assignment
   //=====================================================================================

   // Conversion assignment (0x0)
   {
      test_ = "Column-major HermitianMatrix sparse matrix assignment (0x0)";

      const blaze::CompressedMatrix<cplx,blaze::rowMajor> mat;

      OHT herm;
      herm = mat;

      checkRows    ( herm, 0UL );
      checkColumns ( herm, 0UL );
      checkNonZeros( herm, 0UL );
   }

   // Column-major/row-major sparse matrix assignment (Hermitian)
   {
      test_ = "Column-major/row-major HermitianMatrix sparse matrix assignment (Hermitian)";

      blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 8UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 0);
      mat(2,0) = cplx( 7,-3);
      mat(2,2) = cplx( 3, 0);
      mat.insert( 1UL, 2UL, cplx(0,0) );

      OHT herm;
      herm = mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkNonZeros( herm, 7UL );

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-4,-1) || herm(0,2) != cplx(7,3) ||
          herm(1,0) != cplx(-4, 1) || herm(1,1) != cplx( 2, 0) || herm(1,2) != cplx(0,0) ||
          herm(2,0) != cplx( 7,-3) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) (7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (0,0) )\n"
                                     "( ( 7,-3) ( 0, 0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Column-major/column-major sparse matrix assignment (Hermitian)
   {
      test_ = "Column-major/column-major HermitianMatrix sparse matrix assignment (Hermitian)";

      blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 8UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 0);
      mat(2,0) = cplx( 7,-3);
      mat(2,2) = cplx( 3, 0);
      mat.insert( 1UL, 2UL, cplx(0,0) );

      OHT herm;
      herm = mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkNonZeros( herm, 7UL );

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-4,-1) || herm(0,2) != cplx(7,3) ||
          herm(1,0) != cplx(-4, 1) || herm(1,1) != cplx( 2, 0) || herm(1,2) != cplx(0,0) ||
          herm(2,0) != cplx( 7,-3) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) (7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (0,0) )\n"
                                     "( ( 7,-3) ( 0, 0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Column-major/row-major sparse matrix assignment (invalid diagonal)
   {
      test_ = "Column-major/row-major HermitianMatrix sparse matrix assignment (invalid diagonal)";

      blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 7UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 1);
      mat(2,0) = cplx( 7,-3);
      mat(2,2) = cplx( 3, 0);

      try {
         OHT herm;
         herm = mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/column-major sparse matrix assignment (invalid diagonal)
   {
      test_ = "Column-major/column-major HermitianMatrix sparse matrix assignment (invalid diagonal)";

      blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 7UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 1);
      mat(2,0) = cplx( 7,-3);
      mat(2,2) = cplx( 3, 0);

      try {
         OHT herm;
         herm = mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/row-major sparse matrix assignment (invalid pair)
   {
      test_ = "Column-major/row-major HermitianMatrix sparse matrix assignment (invalid pair)";

      blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 7UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 0);
      mat(2,0) = cplx( 7, 3);
      mat(2,2) = cplx( 3, 0);

      try {
         OHT herm;
         herm = mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/column-major sparse matrix assignment (invalid pair)
   {
      test_ = "Column-major/column-major HermitianMatrix sparse matrix assignment (invalid pair)";

      blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 7UL );
      mat(0,0) = cplx( 1, 0);
      mat(0,1) = cplx(-4,-1);
      mat(0,2) = cplx( 7, 3);
      mat(1,0) = cplx(-4, 1);
      mat(1,1) = cplx( 2, 0);
      mat(2,0) = cplx( 7, 3);
      mat(2,2) = cplx( 3, 0);

      try {
         OHT herm;
         herm = mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/row-major sparse matrix assignment (HermitianMatrix)
   {
      test_ = "Column-major/row-major HermitianMatrix sparse matrix assignment (HermitianMatrix)";

      blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > herm1( 3UL, 7UL );
      herm1(0,0) = cplx( 1, 0);
      herm1(0,1) = cplx(-4,-1);
      herm1(0,2) = cplx( 7, 3);
      herm1(1,1) = cplx( 2, 0);
      herm1(2,2) = cplx( 3, 0);

      OHT herm2;
      herm2 = herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkNonZeros( herm2, 7UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-4,-1) || herm2(0,2) != cplx(7,3) ||
          herm2(1,0) != cplx(-4, 1) || herm2(1,1) != cplx( 2, 0) || herm2(1,2) != cplx(0,0) ||
          herm2(2,0) != cplx( 7,-3) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) (7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (0,0) )\n"
                                     "( ( 7,-3) ( 0, 0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Column-major/column-major sparse matrix assignment (HermitianMatrix)
   {
      test_ = "Column-major/column-major HermitianMatrix sparse matrix assignment (HermitianMatrix)";

      blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > herm1( 3UL, 7UL );
      herm1(0,0) = cplx( 1, 0);
      herm1(0,1) = cplx(-4,-1);
      herm1(0,2) = cplx( 7, 3);
      herm1(1,1) = cplx( 2, 0);
      herm1(2,2) = cplx( 3, 0);

      OHT herm2;
      herm2 = herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkNonZeros( herm2, 7UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-4,-1) || herm2(0,2) != cplx(7,3) ||
          herm2(1,0) != cplx(-4, 1) || herm2(1,1) != cplx( 2, 0) || herm2(1,2) != cplx(0,0) ||
          herm2(2,0) != cplx( 7,-3) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) (7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (0,0) )\n"
                                     "( ( 7,-3) ( 0, 0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the HermitianMatrix addition assignment operators.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the addition assignment operators of the HermitianMatrix
// specialization. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void DenseComplexTest::testAddAssign()
{
   //=====================================================================================
   // Row-major dense matrix addition assignment
   //=====================================================================================

   // Row-major/row-major dense matrix addition assignment (Hermitian)
   {
      test_ = "Row-major/row-major HermitianMatrix dense matrix addition assignment (Hermitian)";

      blaze::DynamicMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx(-2,-1);
      mat(0,2) = cplx( 6,-2);
      mat(1,0) = cplx(-2, 1);
      mat(1,1) = cplx( 3, 0);
      mat(2,0) = cplx( 6, 2);

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      herm += mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 2UL );

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-6,-2) || herm(0,2) != cplx(13,1) ||
          herm(1,0) != cplx(-6, 2) || herm(1,1) != cplx( 5, 0) || herm(1,2) != cplx( 0,0) ||
          herm(2,0) != cplx(13,-1) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Row-major/column-major dense matrix addition assignment (Hermitian)
   {
      test_ = "Row-major/column-major HermitianMatrix dense matrix addition assignment (Hermitian)";

      blaze::DynamicMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx(-2,-1);
      mat(0,2) = cplx( 6,-2);
      mat(1,0) = cplx(-2, 1);
      mat(1,1) = cplx( 3, 0);
      mat(2,0) = cplx( 6, 2);

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      herm += mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 2UL );

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-6,-2) || herm(0,2) != cplx(13,1) ||
          herm(1,0) != cplx(-6, 2) || herm(1,1) != cplx( 5, 0) || herm(1,2) != cplx( 0,0) ||
          herm(2,0) != cplx(13,-1) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Row-major/row-major dense matrix addition assignment (invalid diagonal)
   {
      test_ = "Row-major/row-major HermitianMatrix dense matrix addition assignment (invalid diagonal)";

      blaze::DynamicMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx(-2,-1);
      mat(0,2) = cplx( 6,-2);
      mat(1,0) = cplx(-2, 1);
      mat(1,1) = cplx( 3, 9);
      mat(2,0) = cplx( 6, 2);

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm += mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/column-major dense matrix addition assignment (invalid diagonal)
   {
      test_ = "Row-major/column-major HermitianMatrix dense matrix addition assignment (invalid diagonal)";

      blaze::DynamicMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx(-2,-1);
      mat(0,2) = cplx( 6,-2);
      mat(1,0) = cplx(-2, 1);
      mat(1,1) = cplx( 3, 9);
      mat(2,0) = cplx( 6, 2);

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm += mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/row-major dense matrix addition assignment (invalid pair)
   {
      test_ = "Row-major/row-major HermitianMatrix dense matrix addition assignment (invalid pair)";

      blaze::DynamicMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx(-2,-1);
      mat(0,2) = cplx( 6,-8);
      mat(1,0) = cplx(-2, 1);
      mat(1,1) = cplx( 3, 0);
      mat(2,0) = cplx( 6, 9);

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm += mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/column-major dense matrix addition assignment (invalid pair)
   {
      test_ = "Row-major/column-major HermitianMatrix dense matrix addition assignment (invalid pair)";

      blaze::DynamicMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx(-2,-1);
      mat(0,2) = cplx( 6,-8);
      mat(1,0) = cplx(-2, 1);
      mat(1,1) = cplx( 3, 0);
      mat(2,0) = cplx( 6, 9);

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm += mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/row-major dense matrix addition assignment (HermitianMatrix)
   {
      test_ = "Row-major/row-major HermitianMatrix dense matrix addition assignment (HermitianMatrix)";

      HT herm1( 3UL );
      herm1(0,1) = cplx(-2,-1);
      herm1(0,2) = cplx( 6,-2);
      herm1(1,1) = cplx( 3, 0);

      HT herm2( 3UL );
      herm2(0,0) = cplx( 1, 0);
      herm2(0,1) = cplx(-4,-1);
      herm2(0,2) = cplx( 7, 3);
      herm2(1,1) = cplx( 2, 0);
      herm2(2,2) = cplx( 3, 0);

      herm2 += herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );
      checkNonZeros( herm2, 0UL, 3UL );
      checkNonZeros( herm2, 1UL, 2UL );
      checkNonZeros( herm2, 2UL, 2UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-6,-2) || herm2(0,2) != cplx(13,1) ||
          herm2(1,0) != cplx(-6, 2) || herm2(1,1) != cplx( 5, 0) || herm2(1,2) != cplx( 0,0) ||
          herm2(2,0) != cplx(13,-1) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Row-major/column-major dense matrix addition assignment (HermitianMatrix)
   {
      test_ = "Row-major/column-major HermitianMatrix dense matrix addition assignment (HermitianMatrix)";

      OHT herm1( 3UL );
      herm1(0,1) = cplx(-2,-1);
      herm1(0,2) = cplx( 6,-2);
      herm1(1,1) = cplx( 3, 0);

      HT herm2( 3UL );
      herm2(0,0) = cplx( 1, 0);
      herm2(0,1) = cplx(-4,-1);
      herm2(0,2) = cplx( 7, 3);
      herm2(1,1) = cplx( 2, 0);
      herm2(2,2) = cplx( 3, 0);

      herm2 += herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );
      checkNonZeros( herm2, 0UL, 3UL );
      checkNonZeros( herm2, 1UL, 2UL );
      checkNonZeros( herm2, 2UL, 2UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-6,-2) || herm2(0,2) != cplx(13,1) ||
          herm2(1,0) != cplx(-6, 2) || herm2(1,1) != cplx( 5, 0) || herm2(1,2) != cplx( 0,0) ||
          herm2(2,0) != cplx(13,-1) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major sparse matrix addition assignment
   //=====================================================================================

   // Row-major/row-major sparse matrix addition assignment (Hermitian)
   {
      test_ = "Row-major/row-major HermitianMatrix sparse matrix addition assignment (Hermitian)";

      blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 6UL );
      mat(0,1) = cplx(-2,-1);
      mat(0,2) = cplx( 6,-2);
      mat(1,0) = cplx(-2, 1);
      mat(1,1) = cplx( 3, 0);
      mat(2,0) = cplx( 6, 2);
      mat.insert( 1UL, 2UL, cplx(0,0) );

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      herm += mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 2UL );

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-6,-2) || herm(0,2) != cplx(13,1) ||
          herm(1,0) != cplx(-6, 2) || herm(1,1) != cplx( 5, 0) || herm(1,2) != cplx( 0,0) ||
          herm(2,0) != cplx(13,-1) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Row-major/column-major sparse matrix addition assignment (Hermitian)
   {
      test_ = "Row-major/column-major HermitianMatrix sparse matrix addition assignment (Hermitian)";

      blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 6UL );
      mat(0,1) = cplx(-2,-1);
      mat(0,2) = cplx( 6,-2);
      mat(1,0) = cplx(-2, 1);
      mat(1,1) = cplx( 3, 0);
      mat(2,0) = cplx( 6, 2);
      mat.insert( 1UL, 2UL, cplx(0,0) );

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      herm += mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 2UL );

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-6,-2) || herm(0,2) != cplx(13,1) ||
          herm(1,0) != cplx(-6, 2) || herm(1,1) != cplx( 5, 0) || herm(1,2) != cplx( 0,0) ||
          herm(2,0) != cplx(13,-1) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Row-major/row-major dense matrix addition assignment (invalid diagonal)
   {
      test_ = "Row-major/row-major HermitianMatrix dense matrix addition assignment (invalid diagonal)";

      blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
      mat(0,1) = cplx(-2,-1);
      mat(0,2) = cplx( 6,-2);
      mat(1,0) = cplx(-2, 1);
      mat(1,1) = cplx( 3, 9);
      mat(2,0) = cplx( 6, 2);

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm += mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/column-major dense matrix addition assignment (invalid diagonal)
   {
      test_ = "Row-major/column-major HermitianMatrix dense matrix addition assignment (invalid diagonal)";

      blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
      mat(0,1) = cplx(-2,-1);
      mat(0,2) = cplx( 6,-2);
      mat(1,0) = cplx(-2, 1);
      mat(1,1) = cplx( 3, 9);
      mat(2,0) = cplx( 6, 2);

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm += mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/row-major dense matrix addition assignment (invalid pair)
   {
      test_ = "Row-major/row-major HermitianMatrix dense matrix addition assignment (invalid pair)";

      blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
      mat(0,1) = cplx(-2,-1);
      mat(0,2) = cplx( 6,-8);
      mat(1,0) = cplx(-2, 1);
      mat(1,1) = cplx( 3, 0);
      mat(2,0) = cplx( 6, 9);

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm += mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/column-major dense matrix addition assignment (invalid pair)
   {
      test_ = "Row-major/column-major HermitianMatrix dense matrix addition assignment (invalid pair)";

      blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
      mat(0,1) = cplx(-2,-1);
      mat(0,2) = cplx( 6,-8);
      mat(1,0) = cplx(-2, 1);
      mat(1,1) = cplx( 3, 0);
      mat(2,0) = cplx( 6, 9);

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm += mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/row-major dense matrix addition assignment (HermitianMatrix)
   {
      test_ = "Row-major/row-major HermitianMatrix dense matrix addition assignment (HermitianMatrix)";

      blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > herm1( 3UL, 5UL );
      herm1(0,1) = cplx(-2,-1);
      herm1(0,2) = cplx( 6,-2);
      herm1(1,1) = cplx( 3, 0);

      HT herm2( 3UL );
      herm2(0,0) = cplx( 1, 0);
      herm2(0,1) = cplx(-4,-1);
      herm2(0,2) = cplx( 7, 3);
      herm2(1,1) = cplx( 2, 0);
      herm2(2,2) = cplx( 3, 0);

      herm2 += herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );
      checkNonZeros( herm2, 0UL, 3UL );
      checkNonZeros( herm2, 1UL, 2UL );
      checkNonZeros( herm2, 2UL, 2UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-6,-2) || herm2(0,2) != cplx(13,1) ||
          herm2(1,0) != cplx(-6, 2) || herm2(1,1) != cplx( 5, 0) || herm2(1,2) != cplx( 0,0) ||
          herm2(2,0) != cplx(13,-1) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Row-major/column-major dense matrix addition assignment (HermitianMatrix)
   {
      test_ = "Row-major/column-major HermitianMatrix dense matrix addition assignment (HermitianMatrix)";

      blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > herm1( 3UL, 5UL );
      herm1(0,1) = cplx(-2,-1);
      herm1(0,2) = cplx( 6,-2);
      herm1(1,1) = cplx( 3, 0);

      HT herm2( 3UL );
      herm2(0,0) = cplx( 1, 0);
      herm2(0,1) = cplx(-4,-1);
      herm2(0,2) = cplx( 7, 3);
      herm2(1,1) = cplx( 2, 0);
      herm2(2,2) = cplx( 3, 0);

      herm2 += herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );
      checkNonZeros( herm2, 0UL, 3UL );
      checkNonZeros( herm2, 1UL, 2UL );
      checkNonZeros( herm2, 2UL, 2UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-6,-2) || herm2(0,2) != cplx(13,1) ||
          herm2(1,0) != cplx(-6, 2) || herm2(1,1) != cplx( 5, 0) || herm2(1,2) != cplx( 0,0) ||
          herm2(2,0) != cplx(13,-1) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major dense matrix addition assignment
   //=====================================================================================

   // Column-major/row-major dense matrix addition assignment (Hermitian)
   {
      test_ = "Column-major/row-major HermitianMatrix dense matrix addition assignment (Hermitian)";

      blaze::DynamicMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx(-2,-1);
      mat(0,2) = cplx( 6,-2);
      mat(1,0) = cplx(-2, 1);
      mat(1,1) = cplx( 3, 0);
      mat(2,0) = cplx( 6, 2);

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      herm += mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 2UL );

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-6,-2) || herm(0,2) != cplx(13,1) ||
          herm(1,0) != cplx(-6, 2) || herm(1,1) != cplx( 5, 0) || herm(1,2) != cplx( 0,0) ||
          herm(2,0) != cplx(13,-1) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Column-major/column-major dense matrix addition assignment (Hermitian)
   {
      test_ = "Column-major/column-major HermitianMatrix dense matrix addition assignment (Hermitian)";

      blaze::DynamicMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx(-2,-1);
      mat(0,2) = cplx( 6,-2);
      mat(1,0) = cplx(-2, 1);
      mat(1,1) = cplx( 3, 0);
      mat(2,0) = cplx( 6, 2);

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      herm += mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 2UL );

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-6,-2) || herm(0,2) != cplx(13,1) ||
          herm(1,0) != cplx(-6, 2) || herm(1,1) != cplx( 5, 0) || herm(1,2) != cplx( 0,0) ||
          herm(2,0) != cplx(13,-1) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Column-major/row-major dense matrix addition assignment (invalid diagonal)
   {
      test_ = "Column-major/row-major HermitianMatrix dense matrix addition assignment (invalid diagonal)";

      blaze::DynamicMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx(-2,-1);
      mat(0,2) = cplx( 6,-2);
      mat(1,0) = cplx(-2, 1);
      mat(1,1) = cplx( 3, 9);
      mat(2,0) = cplx( 6, 2);

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm += mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/column-major dense matrix addition assignment (invalid diagonal)
   {
      test_ = "Column-major/column-major HermitianMatrix dense matrix addition assignment (invalid diagonal)";

      blaze::DynamicMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx(-2,-1);
      mat(0,2) = cplx( 6,-2);
      mat(1,0) = cplx(-2, 1);
      mat(1,1) = cplx( 3, 9);
      mat(2,0) = cplx( 6, 2);

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm += mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/row-major dense matrix addition assignment (invalid pair)
   {
      test_ = "Column-major/row-major HermitianMatrix dense matrix addition assignment (invalid pair)";

      blaze::DynamicMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx(-2,-1);
      mat(0,2) = cplx( 6,-8);
      mat(1,0) = cplx(-2, 1);
      mat(1,1) = cplx( 3, 0);
      mat(2,0) = cplx( 6, 9);

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm += mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/column-major dense matrix addition assignment (invalid pair)
   {
      test_ = "Column-major/column-major HermitianMatrix dense matrix addition assignment (invalid pair)";

      blaze::DynamicMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx(-2,-1);
      mat(0,2) = cplx( 6,-8);
      mat(1,0) = cplx(-2, 1);
      mat(1,1) = cplx( 3, 0);
      mat(2,0) = cplx( 6, 9);

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm += mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/row-major dense matrix addition assignment (HermitianMatrix)
   {
      test_ = "Column-major/row-major HermitianMatrix dense matrix addition assignment (HermitianMatrix)";

      HT herm1( 3UL );
      herm1(0,1) = cplx(-2,-1);
      herm1(0,2) = cplx( 6,-2);
      herm1(1,1) = cplx( 3, 0);

      OHT herm2( 3UL );
      herm2(0,0) = cplx( 1, 0);
      herm2(0,1) = cplx(-4,-1);
      herm2(0,2) = cplx( 7, 3);
      herm2(1,1) = cplx( 2, 0);
      herm2(2,2) = cplx( 3, 0);

      herm2 += herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );
      checkNonZeros( herm2, 0UL, 3UL );
      checkNonZeros( herm2, 1UL, 2UL );
      checkNonZeros( herm2, 2UL, 2UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-6,-2) || herm2(0,2) != cplx(13,1) ||
          herm2(1,0) != cplx(-6, 2) || herm2(1,1) != cplx( 5, 0) || herm2(1,2) != cplx( 0,0) ||
          herm2(2,0) != cplx(13,-1) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Column-major/column-major dense matrix addition assignment (HermitianMatrix)
   {
      test_ = "Column-major/column-major HermitianMatrix dense matrix addition assignment (HermitianMatrix)";

      OHT herm1( 3UL );
      herm1(0,1) = cplx(-2,-1);
      herm1(0,2) = cplx( 6,-2);
      herm1(1,1) = cplx( 3, 0);

      OHT herm2( 3UL );
      herm2(0,0) = cplx( 1, 0);
      herm2(0,1) = cplx(-4,-1);
      herm2(0,2) = cplx( 7, 3);
      herm2(1,1) = cplx( 2, 0);
      herm2(2,2) = cplx( 3, 0);

      herm2 += herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );
      checkNonZeros( herm2, 0UL, 3UL );
      checkNonZeros( herm2, 1UL, 2UL );
      checkNonZeros( herm2, 2UL, 2UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-6,-2) || herm2(0,2) != cplx(13,1) ||
          herm2(1,0) != cplx(-6, 2) || herm2(1,1) != cplx( 5, 0) || herm2(1,2) != cplx( 0,0) ||
          herm2(2,0) != cplx(13,-1) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major sparse matrix addition assignment
   //=====================================================================================

   // Column-major/row-major sparse matrix addition assignment (Hermitian)
   {
      test_ = "Column-major/row-major HermitianMatrix sparse matrix addition assignment (Hermitian)";

      blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 6UL );
      mat(0,1) = cplx(-2,-1);
      mat(0,2) = cplx( 6,-2);
      mat(1,0) = cplx(-2, 1);
      mat(1,1) = cplx( 3, 0);
      mat(2,0) = cplx( 6, 2);
      mat.insert( 1UL, 2UL, cplx(0,0) );

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      herm += mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 2UL );

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-6,-2) || herm(0,2) != cplx(13,1) ||
          herm(1,0) != cplx(-6, 2) || herm(1,1) != cplx( 5, 0) || herm(1,2) != cplx( 0,0) ||
          herm(2,0) != cplx(13,-1) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Column-major/column-major sparse matrix addition assignment (Hermitian)
   {
      test_ = "Column-major/column-major HermitianMatrix sparse matrix addition assignment (Hermitian)";

      blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 6UL );
      mat(0,1) = cplx(-2,-1);
      mat(0,2) = cplx( 6,-2);
      mat(1,0) = cplx(-2, 1);
      mat(1,1) = cplx( 3, 0);
      mat(2,0) = cplx( 6, 2);
      mat.insert( 1UL, 2UL, cplx(0,0) );

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      herm += mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 2UL );

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-6,-2) || herm(0,2) != cplx(13,1) ||
          herm(1,0) != cplx(-6, 2) || herm(1,1) != cplx( 5, 0) || herm(1,2) != cplx( 0,0) ||
          herm(2,0) != cplx(13,-1) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Column-major/row-major dense matrix addition assignment (invalid diagonal)
   {
      test_ = "Column-major/row-major HermitianMatrix dense matrix addition assignment (invalid diagonal)";

      blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
      mat(0,1) = cplx(-2,-1);
      mat(0,2) = cplx( 6,-2);
      mat(1,0) = cplx(-2, 1);
      mat(1,1) = cplx( 3, 9);
      mat(2,0) = cplx( 6, 2);

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm += mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/column-major dense matrix addition assignment (invalid diagonal)
   {
      test_ = "Column-major/column-major HermitianMatrix dense matrix addition assignment (invalid diagonal)";

      blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
      mat(0,1) = cplx(-2,-1);
      mat(0,2) = cplx( 6,-2);
      mat(1,0) = cplx(-2, 1);
      mat(1,1) = cplx( 3, 9);
      mat(2,0) = cplx( 6, 2);

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm += mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/row-major dense matrix addition assignment (invalid pair)
   {
      test_ = "Column-major/row-major HermitianMatrix dense matrix addition assignment (invalid pair)";

      blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
      mat(0,1) = cplx(-2,-1);
      mat(0,2) = cplx( 6,-8);
      mat(1,0) = cplx(-2, 1);
      mat(1,1) = cplx( 3, 0);
      mat(2,0) = cplx( 6, 9);

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm += mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/column-major dense matrix addition assignment (invalid pair)
   {
      test_ = "Column-major/column-major HermitianMatrix dense matrix addition assignment (invalid pair)";

      blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
      mat(0,1) = cplx(-2,-1);
      mat(0,2) = cplx( 6,-8);
      mat(1,0) = cplx(-2, 1);
      mat(1,1) = cplx( 3, 0);
      mat(2,0) = cplx( 6, 9);

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm += mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/row-major dense matrix addition assignment (HermitianMatrix)
   {
      test_ = "Column-major/row-major HermitianMatrix dense matrix addition assignment (HermitianMatrix)";

      blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > herm1( 3UL, 5UL );
      herm1(0,1) = cplx(-2,-1);
      herm1(0,2) = cplx( 6,-2);
      herm1(1,1) = cplx( 3, 0);

      OHT herm2( 3UL );
      herm2(0,0) = cplx( 1, 0);
      herm2(0,1) = cplx(-4,-1);
      herm2(0,2) = cplx( 7, 3);
      herm2(1,1) = cplx( 2, 0);
      herm2(2,2) = cplx( 3, 0);

      herm2 += herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );
      checkNonZeros( herm2, 0UL, 3UL );
      checkNonZeros( herm2, 1UL, 2UL );
      checkNonZeros( herm2, 2UL, 2UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-6,-2) || herm2(0,2) != cplx(13,1) ||
          herm2(1,0) != cplx(-6, 2) || herm2(1,1) != cplx( 5, 0) || herm2(1,2) != cplx( 0,0) ||
          herm2(2,0) != cplx(13,-1) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Column-major/column-major dense matrix addition assignment (HermitianMatrix)
   {
      test_ = "Column-major/column-major HermitianMatrix dense matrix addition assignment (HermitianMatrix)";

      blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > herm1( 3UL, 5UL );
      herm1(0,1) = cplx(-2,-1);
      herm1(0,2) = cplx( 6,-2);
      herm1(1,1) = cplx( 3, 0);

      OHT herm2( 3UL );
      herm2(0,0) = cplx( 1, 0);
      herm2(0,1) = cplx(-4,-1);
      herm2(0,2) = cplx( 7, 3);
      herm2(1,1) = cplx( 2, 0);
      herm2(2,2) = cplx( 3, 0);

      herm2 += herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );
      checkNonZeros( herm2, 0UL, 3UL );
      checkNonZeros( herm2, 1UL, 2UL );
      checkNonZeros( herm2, 2UL, 2UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-6,-2) || herm2(0,2) != cplx(13,1) ||
          herm2(1,0) != cplx(-6, 2) || herm2(1,1) != cplx( 5, 0) || herm2(1,2) != cplx( 0,0) ||
          herm2(2,0) != cplx(13,-1) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the HermitianMatrix subtraction assignment operators.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the subtraction assignment operators of the HermitianMatrix
// specialization. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void DenseComplexTest::testSubAssign()
{
   //=====================================================================================
   // Row-major dense matrix subtraction assignment
   //=====================================================================================

   // Row-major/row-major dense matrix subtraction assignment (Hermitian)
   {
      test_ = "Row-major/row-major HermitianMatrix dense matrix subtraction assignment (Hermitian)";

      blaze::DynamicMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx( 2, 1);
      mat(0,2) = cplx(-6, 2);
      mat(1,0) = cplx( 2,-1);
      mat(1,1) = cplx(-3, 0);
      mat(2,0) = cplx(-6,-2);

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      herm -= mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 2UL );

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-6,-2) || herm(0,2) != cplx(13,1) ||
          herm(1,0) != cplx(-6, 2) || herm(1,1) != cplx( 5, 0) || herm(1,2) != cplx( 0,0) ||
          herm(2,0) != cplx(13,-1) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Row-major/column-major dense matrix subtraction assignment (Hermitian)
   {
      test_ = "Row-major/column-major HermitianMatrix dense matrix subtraction assignment (Hermitian)";

      blaze::DynamicMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx( 2, 1);
      mat(0,2) = cplx(-6, 2);
      mat(1,0) = cplx( 2,-1);
      mat(1,1) = cplx(-3, 0);
      mat(2,0) = cplx(-6,-2);

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      herm -= mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 2UL );

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-6,-2) || herm(0,2) != cplx(13,1) ||
          herm(1,0) != cplx(-6, 2) || herm(1,1) != cplx( 5, 0) || herm(1,2) != cplx( 0,0) ||
          herm(2,0) != cplx(13,-1) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Row-major/row-major dense matrix subtraction assignment (invalid diagonal)
   {
      test_ = "Row-major/row-major HermitianMatrix dense matrix subtraction assignment (invalid diagonal)";

      blaze::DynamicMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx( 2, 1);
      mat(0,2) = cplx(-6, 2);
      mat(1,0) = cplx( 2,-1);
      mat(1,1) = cplx(-3,-9);
      mat(2,0) = cplx(-6,-2);

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm -= mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/column-major dense matrix subtraction assignment (invalid diagonal)
   {
      test_ = "Row-major/column-major HermitianMatrix dense matrix subtraction assignment (invalid diagonal)";

      blaze::DynamicMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx( 2, 1);
      mat(0,2) = cplx(-6, 2);
      mat(1,0) = cplx( 2,-1);
      mat(1,1) = cplx(-3,-9);
      mat(2,0) = cplx(-6,-2);

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm -= mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/row-major dense matrix subtraction assignment (invalid pair)
   {
      test_ = "Row-major/row-major HermitianMatrix dense matrix subtraction assignment (invalid pair)";

      blaze::DynamicMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx( 2, 1);
      mat(0,2) = cplx(-6, 8);
      mat(1,0) = cplx( 2,-1);
      mat(1,1) = cplx(-3, 0);
      mat(2,0) = cplx(-6,-9);

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm -= mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/column-major dense matrix subtraction assignment (invalid pair)
   {
      test_ = "Row-major/column-major HermitianMatrix dense matrix subtraction assignment (invalid pair)";

      blaze::DynamicMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx( 2, 1);
      mat(0,2) = cplx(-6, 8);
      mat(1,0) = cplx( 2,-1);
      mat(1,1) = cplx(-3, 0);
      mat(2,0) = cplx(-6,-9);

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm -= mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/row-major dense matrix subtraction assignment (HermitianMatrix)
   {
      test_ = "Row-major/row-major HermitianMatrix dense matrix subtraction assignment (HermitianMatrix)";

      HT herm1( 3UL );
      herm1(0,1) = cplx( 2,1);
      herm1(0,2) = cplx(-6,2);
      herm1(1,1) = cplx(-3,0);

      HT herm2( 3UL );
      herm2(0,0) = cplx( 1, 0);
      herm2(0,1) = cplx(-4,-1);
      herm2(0,2) = cplx( 7, 3);
      herm2(1,1) = cplx( 2, 0);
      herm2(2,2) = cplx( 3, 0);

      herm2 -= herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );
      checkNonZeros( herm2, 0UL, 3UL );
      checkNonZeros( herm2, 1UL, 2UL );
      checkNonZeros( herm2, 2UL, 2UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-6,-2) || herm2(0,2) != cplx(13,1) ||
          herm2(1,0) != cplx(-6, 2) || herm2(1,1) != cplx( 5, 0) || herm2(1,2) != cplx( 0,0) ||
          herm2(2,0) != cplx(13,-1) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Row-major/column-major dense matrix subtraction assignment (HermitianMatrix)
   {
      test_ = "Row-major/column-major HermitianMatrix dense matrix subtraction assignment (HermitianMatrix)";

      OHT herm1( 3UL );
      herm1(0,1) = cplx( 2,1);
      herm1(0,2) = cplx(-6,2);
      herm1(1,1) = cplx(-3,0);

      HT herm2( 3UL );
      herm2(0,0) = cplx( 1, 0);
      herm2(0,1) = cplx(-4,-1);
      herm2(0,2) = cplx( 7, 3);
      herm2(1,1) = cplx( 2, 0);
      herm2(2,2) = cplx( 3, 0);

      herm2 -= herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );
      checkNonZeros( herm2, 0UL, 3UL );
      checkNonZeros( herm2, 1UL, 2UL );
      checkNonZeros( herm2, 2UL, 2UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-6,-2) || herm2(0,2) != cplx(13,1) ||
          herm2(1,0) != cplx(-6, 2) || herm2(1,1) != cplx( 5, 0) || herm2(1,2) != cplx( 0,0) ||
          herm2(2,0) != cplx(13,-1) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major sparse matrix subtraction assignment
   //=====================================================================================

   // Row-major/row-major sparse matrix subtraction assignment (Hermitian)
   {
      test_ = "Row-major/row-major HermitianMatrix sparse matrix subtraction assignment (Hermitian)";

      blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 6UL );
      mat(0,1) = cplx( 2, 1);
      mat(0,2) = cplx(-6, 2);
      mat(1,0) = cplx( 2,-1);
      mat(1,1) = cplx(-3, 0);
      mat(2,0) = cplx(-6,-2);
      mat.insert( 1UL, 2UL, cplx(0,0) );

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      herm -= mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 2UL );

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-6,-2) || herm(0,2) != cplx(13,1) ||
          herm(1,0) != cplx(-6, 2) || herm(1,1) != cplx( 5, 0) || herm(1,2) != cplx( 0,0) ||
          herm(2,0) != cplx(13,-1) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Row-major/column-major sparse matrix subtraction assignment (Hermitian)
   {
      test_ = "Row-major/column-major HermitianMatrix sparse matrix subtraction assignment (Hermitian)";

      blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 6UL );
      mat(0,1) = cplx( 2, 1);
      mat(0,2) = cplx(-6, 2);
      mat(1,0) = cplx( 2,-1);
      mat(1,1) = cplx(-3, 0);
      mat(2,0) = cplx(-6,-2);
      mat.insert( 1UL, 2UL, cplx(0,0) );

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      herm -= mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 2UL );

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-6,-2) || herm(0,2) != cplx(13,1) ||
          herm(1,0) != cplx(-6, 2) || herm(1,1) != cplx( 5, 0) || herm(1,2) != cplx( 0,0) ||
          herm(2,0) != cplx(13,-1) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Row-major/row-major dense matrix subtraction assignment (invalid diagonal)
   {
      test_ = "Row-major/row-major HermitianMatrix dense matrix subtraction assignment (invalid diagonal)";

      blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
      mat(0,1) = cplx( 2, 1);
      mat(0,2) = cplx(-6, 2);
      mat(1,0) = cplx( 2,-1);
      mat(1,1) = cplx(-3,-9);
      mat(2,0) = cplx(-6,-2);

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm -= mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/column-major dense matrix subtraction assignment (invalid diagonal)
   {
      test_ = "Row-major/column-major HermitianMatrix dense matrix subtraction assignment (invalid diagonal)";

      blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
      mat(0,1) = cplx( 2, 1);
      mat(0,2) = cplx(-6, 2);
      mat(1,0) = cplx( 2,-1);
      mat(1,1) = cplx(-3,-9);
      mat(2,0) = cplx(-6,-2);

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm -= mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/row-major dense matrix subtraction assignment (invalid pair)
   {
      test_ = "Row-major/row-major HermitianMatrix dense matrix subtraction assignment (invalid pair)";

      blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
      mat(0,1) = cplx( 2, 1);
      mat(0,2) = cplx(-6, 8);
      mat(1,0) = cplx( 2,-1);
      mat(1,1) = cplx(-3, 0);
      mat(2,0) = cplx(-6,-9);

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm -= mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/column-major dense matrix subtraction assignment (invalid pair)
   {
      test_ = "Row-major/column-major HermitianMatrix dense matrix subtraction assignment (invalid pair)";

      blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
      mat(0,1) = cplx( 2, 1);
      mat(0,2) = cplx(-6, 8);
      mat(1,0) = cplx( 2,-1);
      mat(1,1) = cplx(-3, 0);
      mat(2,0) = cplx(-6,-9);

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm -= mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/row-major dense matrix subtraction assignment (HermitianMatrix)
   {
      test_ = "Row-major/row-major HermitianMatrix dense matrix subtraction assignment (HermitianMatrix)";

      blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > herm1( 3UL, 5UL );
      herm1(0,1) = cplx( 2,1);
      herm1(0,2) = cplx(-6,2);
      herm1(1,1) = cplx(-3,0);

      HT herm2( 3UL );
      herm2(0,0) = cplx( 1, 0);
      herm2(0,1) = cplx(-4,-1);
      herm2(0,2) = cplx( 7, 3);
      herm2(1,1) = cplx( 2, 0);
      herm2(2,2) = cplx( 3, 0);

      herm2 -= herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );
      checkNonZeros( herm2, 0UL, 3UL );
      checkNonZeros( herm2, 1UL, 2UL );
      checkNonZeros( herm2, 2UL, 2UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-6,-2) || herm2(0,2) != cplx(13,1) ||
          herm2(1,0) != cplx(-6, 2) || herm2(1,1) != cplx( 5, 0) || herm2(1,2) != cplx( 0,0) ||
          herm2(2,0) != cplx(13,-1) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Row-major/column-major dense matrix subtraction assignment (HermitianMatrix)
   {
      test_ = "Row-major/column-major HermitianMatrix dense matrix subtraction assignment (HermitianMatrix)";

      blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > herm1( 3UL, 5UL );
      herm1(0,1) = cplx( 2,1);
      herm1(0,2) = cplx(-6,2);
      herm1(1,1) = cplx(-3,0);

      HT herm2( 3UL );
      herm2(0,0) = cplx( 1, 0);
      herm2(0,1) = cplx(-4,-1);
      herm2(0,2) = cplx( 7, 3);
      herm2(1,1) = cplx( 2, 0);
      herm2(2,2) = cplx( 3, 0);

      herm2 -= herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );
      checkNonZeros( herm2, 0UL, 3UL );
      checkNonZeros( herm2, 1UL, 2UL );
      checkNonZeros( herm2, 2UL, 2UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-6,-2) || herm2(0,2) != cplx(13,1) ||
          herm2(1,0) != cplx(-6, 2) || herm2(1,1) != cplx( 5, 0) || herm2(1,2) != cplx( 0,0) ||
          herm2(2,0) != cplx(13,-1) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major dense matrix subtraction assignment
   //=====================================================================================

   // Column-major/row-major dense matrix subtraction assignment (Hermitian)
   {
      test_ = "Column-major/row-major HermitianMatrix dense matrix subtraction assignment (Hermitian)";

      blaze::DynamicMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx( 2, 1);
      mat(0,2) = cplx(-6, 2);
      mat(1,0) = cplx( 2,-1);
      mat(1,1) = cplx(-3, 0);
      mat(2,0) = cplx(-6,-2);

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      herm -= mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 2UL );

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-6,-2) || herm(0,2) != cplx(13,1) ||
          herm(1,0) != cplx(-6, 2) || herm(1,1) != cplx( 5, 0) || herm(1,2) != cplx( 0,0) ||
          herm(2,0) != cplx(13,-1) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Column-major/column-major dense matrix subtraction assignment (Hermitian)
   {
      test_ = "Column-major/column-major HermitianMatrix dense matrix subtraction assignment (Hermitian)";

      blaze::DynamicMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx( 2, 1);
      mat(0,2) = cplx(-6, 2);
      mat(1,0) = cplx( 2,-1);
      mat(1,1) = cplx(-3, 0);
      mat(2,0) = cplx(-6,-2);

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      herm -= mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 2UL );

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-6,-2) || herm(0,2) != cplx(13,1) ||
          herm(1,0) != cplx(-6, 2) || herm(1,1) != cplx( 5, 0) || herm(1,2) != cplx( 0,0) ||
          herm(2,0) != cplx(13,-1) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Column-major/row-major dense matrix subtraction assignment (invalid diagonal)
   {
      test_ = "Column-major/row-major HermitianMatrix dense matrix subtraction assignment (invalid diagonal)";

      blaze::DynamicMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx( 2, 1);
      mat(0,2) = cplx(-6, 2);
      mat(1,0) = cplx( 2,-1);
      mat(1,1) = cplx(-3,-9);
      mat(2,0) = cplx(-6,-2);

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm -= mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/column-major dense matrix subtraction assignment (invalid diagonal)
   {
      test_ = "Column-major/column-major HermitianMatrix dense matrix subtraction assignment (invalid diagonal)";

      blaze::DynamicMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx( 2, 1);
      mat(0,2) = cplx(-6, 2);
      mat(1,0) = cplx( 2,-1);
      mat(1,1) = cplx(-3,-9);
      mat(2,0) = cplx(-6,-2);

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm -= mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/row-major dense matrix subtraction assignment (invalid pair)
   {
      test_ = "Column-major/row-major HermitianMatrix dense matrix subtraction assignment (invalid pair)";

      blaze::DynamicMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx( 2, 1);
      mat(0,2) = cplx(-6, 8);
      mat(1,0) = cplx( 2,-1);
      mat(1,1) = cplx(-3, 0);
      mat(2,0) = cplx(-6,-9);

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm -= mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/column-major dense matrix subtraction assignment (invalid pair)
   {
      test_ = "Column-major/column-major HermitianMatrix dense matrix subtraction assignment (invalid pair)";

      blaze::DynamicMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx( 2, 1);
      mat(0,2) = cplx(-6, 8);
      mat(1,0) = cplx( 2,-1);
      mat(1,1) = cplx(-3, 0);
      mat(2,0) = cplx(-6,-9);

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm -= mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/row-major dense matrix subtraction assignment (HermitianMatrix)
   {
      test_ = "Column-major/row-major HermitianMatrix dense matrix subtraction assignment (HermitianMatrix)";

      HT herm1( 3UL );
      herm1(0,1) = cplx( 2,1);
      herm1(0,2) = cplx(-6,2);
      herm1(1,1) = cplx(-3,0);

      OHT herm2( 3UL );
      herm2(0,0) = cplx( 1, 0);
      herm2(0,1) = cplx(-4,-1);
      herm2(0,2) = cplx( 7, 3);
      herm2(1,1) = cplx( 2, 0);
      herm2(2,2) = cplx( 3, 0);

      herm2 -= herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );
      checkNonZeros( herm2, 0UL, 3UL );
      checkNonZeros( herm2, 1UL, 2UL );
      checkNonZeros( herm2, 2UL, 2UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-6,-2) || herm2(0,2) != cplx(13,1) ||
          herm2(1,0) != cplx(-6, 2) || herm2(1,1) != cplx( 5, 0) || herm2(1,2) != cplx( 0,0) ||
          herm2(2,0) != cplx(13,-1) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Column-major/column-major dense matrix subtraction assignment (HermitianMatrix)
   {
      test_ = "Column-major/column-major HermitianMatrix dense matrix subtraction assignment (HermitianMatrix)";

      OHT herm1( 3UL );
      herm1(0,1) = cplx( 2,1);
      herm1(0,2) = cplx(-6,2);
      herm1(1,1) = cplx(-3,0);

      OHT herm2( 3UL );
      herm2(0,0) = cplx( 1, 0);
      herm2(0,1) = cplx(-4,-1);
      herm2(0,2) = cplx( 7, 3);
      herm2(1,1) = cplx( 2, 0);
      herm2(2,2) = cplx( 3, 0);

      herm2 -= herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );
      checkNonZeros( herm2, 0UL, 3UL );
      checkNonZeros( herm2, 1UL, 2UL );
      checkNonZeros( herm2, 2UL, 2UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-6,-2) || herm2(0,2) != cplx(13,1) ||
          herm2(1,0) != cplx(-6, 2) || herm2(1,1) != cplx( 5, 0) || herm2(1,2) != cplx( 0,0) ||
          herm2(2,0) != cplx(13,-1) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major sparse matrix subtraction assignment
   //=====================================================================================

   // Column-major/row-major sparse matrix subtraction assignment (Hermitian)
   {
      test_ = "Column-major/row-major HermitianMatrix sparse matrix subtraction assignment (Hermitian)";

      blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 6UL );
      mat(0,1) = cplx( 2, 1);
      mat(0,2) = cplx(-6, 2);
      mat(1,0) = cplx( 2,-1);
      mat(1,1) = cplx(-3, 0);
      mat(2,0) = cplx(-6,-2);
      mat.insert( 1UL, 2UL, cplx(0,0) );

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      herm -= mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 2UL );

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-6,-2) || herm(0,2) != cplx(13,1) ||
          herm(1,0) != cplx(-6, 2) || herm(1,1) != cplx( 5, 0) || herm(1,2) != cplx( 0,0) ||
          herm(2,0) != cplx(13,-1) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Column-major/column-major sparse matrix subtraction assignment (Hermitian)
   {
      test_ = "Column-major/column-major HermitianMatrix sparse matrix subtraction assignment (Hermitian)";

      blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 6UL );
      mat(0,1) = cplx( 2, 1);
      mat(0,2) = cplx(-6, 2);
      mat(1,0) = cplx( 2,-1);
      mat(1,1) = cplx(-3, 0);
      mat(2,0) = cplx(-6,-2);
      mat.insert( 1UL, 2UL, cplx(0,0) );

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      herm -= mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 2UL );

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-6,-2) || herm(0,2) != cplx(13,1) ||
          herm(1,0) != cplx(-6, 2) || herm(1,1) != cplx( 5, 0) || herm(1,2) != cplx( 0,0) ||
          herm(2,0) != cplx(13,-1) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Column-major/row-major dense matrix subtraction assignment (invalid diagonal)
   {
      test_ = "Column-major/row-major HermitianMatrix dense matrix subtraction assignment (invalid diagonal)";

      blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
      mat(0,1) = cplx( 2, 1);
      mat(0,2) = cplx(-6, 2);
      mat(1,0) = cplx( 2,-1);
      mat(1,1) = cplx(-3,-9);
      mat(2,0) = cplx(-6,-2);

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm -= mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/column-major dense matrix subtraction assignment (invalid diagonal)
   {
      test_ = "Column-major/column-major HermitianMatrix dense matrix subtraction assignment (invalid diagonal)";

      blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
      mat(0,1) = cplx( 2, 1);
      mat(0,2) = cplx(-6, 2);
      mat(1,0) = cplx( 2,-1);
      mat(1,1) = cplx(-3,-9);
      mat(2,0) = cplx(-6,-2);

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm -= mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/row-major dense matrix subtraction assignment (invalid pair)
   {
      test_ = "Column-major/row-major HermitianMatrix dense matrix subtraction assignment (invalid pair)";

      blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
      mat(0,1) = cplx( 2, 1);
      mat(0,2) = cplx(-6, 8);
      mat(1,0) = cplx( 2,-1);
      mat(1,1) = cplx(-3, 0);
      mat(2,0) = cplx(-6,-9);

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm -= mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/column-major dense matrix subtraction assignment (invalid pair)
   {
      test_ = "Column-major/column-major HermitianMatrix dense matrix subtraction assignment (invalid pair)";

      blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
      mat(0,1) = cplx( 2, 1);
      mat(0,2) = cplx(-6, 8);
      mat(1,0) = cplx( 2,-1);
      mat(1,1) = cplx(-3, 0);
      mat(2,0) = cplx(-6,-9);

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      try {
         herm -= mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/row-major dense matrix subtraction assignment (HermitianMatrix)
   {
      test_ = "Column-major/row-major HermitianMatrix dense matrix subtraction assignment (HermitianMatrix)";

      blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > herm1( 3UL, 5UL );
      herm1(0,1) = cplx( 2,1);
      herm1(0,2) = cplx(-6,2);
      herm1(1,1) = cplx(-3,0);

      OHT herm2( 3UL );
      herm2(0,0) = cplx( 1, 0);
      herm2(0,1) = cplx(-4,-1);
      herm2(0,2) = cplx( 7, 3);
      herm2(1,1) = cplx( 2, 0);
      herm2(2,2) = cplx( 3, 0);

      herm2 -= herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );
      checkNonZeros( herm2, 0UL, 3UL );
      checkNonZeros( herm2, 1UL, 2UL );
      checkNonZeros( herm2, 2UL, 2UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-6,-2) || herm2(0,2) != cplx(13,1) ||
          herm2(1,0) != cplx(-6, 2) || herm2(1,1) != cplx( 5, 0) || herm2(1,2) != cplx( 0,0) ||
          herm2(2,0) != cplx(13,-1) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Column-major/column-major dense matrix subtraction assignment (HermitianMatrix)
   {
      test_ = "Column-major/column-major HermitianMatrix dense matrix subtraction assignment (HermitianMatrix)";

      blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > herm1( 3UL, 5UL );
      herm1(0,1) = cplx( 2,1);
      herm1(0,2) = cplx(-6,2);
      herm1(1,1) = cplx(-3,0);

      OHT herm2( 3UL );
      herm2(0,0) = cplx( 1, 0);
      herm2(0,1) = cplx(-4,-1);
      herm2(0,2) = cplx( 7, 3);
      herm2(1,1) = cplx( 2, 0);
      herm2(2,2) = cplx( 3, 0);

      herm2 -= herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );
      checkNonZeros( herm2, 0UL, 3UL );
      checkNonZeros( herm2, 1UL, 2UL );
      checkNonZeros( herm2, 2UL, 2UL );

      if( herm2(0,0) != cplx( 1, 0) || herm2(0,1) != cplx(-6,-2) || herm2(0,2) != cplx(13,1) ||
          herm2(1,0) != cplx(-6, 2) || herm2(1,1) != cplx( 5, 0) || herm2(1,2) != cplx( 0,0) ||
          herm2(2,0) != cplx(13,-1) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( ( 1, 0) (-6,-2) (13,1) )\n"
                                     "( (-6, 2) ( 5, 0) ( 0,0) )\n"
                                     "( (13,-1) ( 0, 0) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the HermitianMatrix multiplication assignment operators.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the multiplication assignment operators of the HermitianMatrix
// specialization. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void DenseComplexTest::testMultAssign()
{
   //=====================================================================================
   // Row-major dense matrix multiplication assignment
   //=====================================================================================

   // Row-major/row-major dense matrix multiplication assignment (Hermitian)
   {
      test_ = "Row-major/row-major HermitianMatrix dense matrix multiplication assignment (Hermitian)";

      blaze::DynamicMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,0) = cplx(2,0);
      mat(1,1) = cplx(2,0);
      mat(2,2) = cplx(2,0);

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      herm *= mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 2UL );

      if( herm(0,0) != cplx( 2, 0) || herm(0,1) != cplx(-8,-2) || herm(0,2) != cplx(14,6) ||
          herm(1,0) != cplx(-8, 2) || herm(1,1) != cplx( 4, 0) || herm(1,2) != cplx( 0,0) ||
          herm(2,0) != cplx(14,-6) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx( 6,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n(  2 -8 14 )\n"
                                     "( -8  4  0 )\n"
                                     "( 14  0  6 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Row-major/column-major dense matrix multiplication assignment (Hermitian)
   {
      test_ = "Row-major/column-major HermitianMatrix dense matrix multiplication assignment (Hermitian)";

      blaze::DynamicMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,0) = cplx(2,0);
      mat(1,1) = cplx(2,0);
      mat(2,2) = cplx(2,0);

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      herm *= mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 2UL );

      if( herm(0,0) != cplx( 2, 0) || herm(0,1) != cplx(-8,-2) || herm(0,2) != cplx(14,6) ||
          herm(1,0) != cplx(-8, 2) || herm(1,1) != cplx( 4, 0) || herm(1,2) != cplx( 0,0) ||
          herm(2,0) != cplx(14,-6) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx( 6,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n(  2 -8 14 )\n"
                                     "( -8  4  0 )\n"
                                     "( 14  0  6 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Row-major/row-major dense matrix multiplication assignment (non-Hermitian)
   {
      test_ = "Row-major/row-major HermitianMatrix dense matrix multiplication assignment (non-Hermitian)";

      blaze::DynamicMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx(-2,-2);
      mat(0,2) = cplx( 6, 1);
      mat(1,1) = cplx( 3, 0);
      mat(2,0) = cplx( 6, 3);

      HT herm( 3UL );
      herm(0,0) = cplx( 1,0);
      herm(0,1) = cplx(-4,0);
      herm(0,2) = cplx( 7,0);
      herm(1,1) = cplx( 2,0);
      herm(2,2) = cplx( 3,0);

      try {
         herm *= mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/column-major dense matrix multiplication assignment (non-Hermitian)
   {
      test_ = "Row-major/column-major HermitianMatrix dense matrix multiplication assignment (non-Hermitian)";

      blaze::DynamicMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx(-2,-2);
      mat(0,2) = cplx( 6, 1);
      mat(1,1) = cplx( 3, 0);
      mat(2,0) = cplx( 6, 3);

      HT herm( 3UL );
      herm(0,0) = cplx( 1,0);
      herm(0,1) = cplx(-4,0);
      herm(0,2) = cplx( 7,0);
      herm(1,1) = cplx( 2,0);
      herm(2,2) = cplx( 3,0);

      try {
         herm *= mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/row-major dense matrix multiplication assignment (HermitianMatrix)
   {
      test_ = "Row-major/row-major HermitianMatrix dense matrix multiplication assignment (HermitianMatrix)";

      HT herm1( 3UL );
      herm1(0,0) = cplx(2,0);
      herm1(1,1) = cplx(2,0);
      herm1(2,2) = cplx(2,0);

      HT herm2( 3UL );
      herm2(0,0) = cplx( 1, 0);
      herm2(0,1) = cplx(-4,-1);
      herm2(0,2) = cplx( 7, 3);
      herm2(1,1) = cplx( 2, 0);
      herm2(2,2) = cplx( 3, 0);

      herm2 *= herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );
      checkNonZeros( herm2, 0UL, 3UL );
      checkNonZeros( herm2, 1UL, 2UL );
      checkNonZeros( herm2, 2UL, 2UL );

      if( herm2(0,0) != cplx( 2, 0) || herm2(0,1) != cplx(-8,-2) || herm2(0,2) != cplx(14,6) ||
          herm2(1,0) != cplx(-8, 2) || herm2(1,1) != cplx( 4, 0) || herm2(1,2) != cplx( 0,0) ||
          herm2(2,0) != cplx(14,-6) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx( 6,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n(  2 -8 14 )\n"
                                     "( -8  4  0 )\n"
                                     "( 14  0  6 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Row-major/column-major dense matrix multiplication assignment (HermitianMatrix)
   {
      test_ = "Row-major/column-major HermitianMatrix dense matrix multiplication assignment (HermitianMatrix)";

      OHT herm1( 3UL );
      herm1(0,0) = cplx(2,0);
      herm1(1,1) = cplx(2,0);
      herm1(2,2) = cplx(2,0);

      HT herm2( 3UL );
      herm2(0,0) = cplx( 1, 0);
      herm2(0,1) = cplx(-4,-1);
      herm2(0,2) = cplx( 7, 3);
      herm2(1,1) = cplx( 2, 0);
      herm2(2,2) = cplx( 3, 0);

      herm2 *= herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );
      checkNonZeros( herm2, 0UL, 3UL );
      checkNonZeros( herm2, 1UL, 2UL );
      checkNonZeros( herm2, 2UL, 2UL );

      if( herm2(0,0) != cplx( 2, 0) || herm2(0,1) != cplx(-8,-2) || herm2(0,2) != cplx(14,6) ||
          herm2(1,0) != cplx(-8, 2) || herm2(1,1) != cplx( 4, 0) || herm2(1,2) != cplx( 0,0) ||
          herm2(2,0) != cplx(14,-6) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx( 6,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n(  2 -8 14 )\n"
                                     "( -8  4  0 )\n"
                                     "( 14  0  6 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major sparse matrix multiplication assignment
   //=====================================================================================

   // Row-major/row-major sparse matrix multiplication assignment (Hermitian)
   {
      test_ = "Row-major/row-major HermitianMatrix sparse matrix multiplication assignment (Hermitian)";

      blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 4UL );
      mat(0,0) = cplx(2,0);
      mat(1,1) = cplx(2,0);
      mat(2,2) = cplx(2,0);
      mat.insert( 1UL, 2UL, cplx(0,0) );

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      herm *= mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 2UL );

      if( herm(0,0) != cplx( 2, 0) || herm(0,1) != cplx(-8,-2) || herm(0,2) != cplx(14,6) ||
          herm(1,0) != cplx(-8, 2) || herm(1,1) != cplx( 4, 0) || herm(1,2) != cplx( 0,0) ||
          herm(2,0) != cplx(14,-6) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx( 6,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n(  2 -8 14 )\n"
                                     "( -8  4  0 )\n"
                                     "( 14  0  6 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Row-major/column-major sparse matrix multiplication assignment (Hermitian)
   {
      test_ = "Row-major/column-major HermitianMatrix sparse matrix multiplication assignment (Hermitian)";

      blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 4UL );
      mat(0,0) = cplx(2,0);
      mat(1,1) = cplx(2,0);
      mat(2,2) = cplx(2,0);
      mat.insert( 1UL, 2UL, cplx(0,0) );

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      herm *= mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 2UL );

      if( herm(0,0) != cplx( 2, 0) || herm(0,1) != cplx(-8,-2) || herm(0,2) != cplx(14,6) ||
          herm(1,0) != cplx(-8, 2) || herm(1,1) != cplx( 4, 0) || herm(1,2) != cplx( 0,0) ||
          herm(2,0) != cplx(14,-6) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx( 6,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n(  2 -8 14 )\n"
                                     "( -8  4  0 )\n"
                                     "( 14  0  6 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Row-major/row-major sparse matrix multiplication assignment (non-Hermitian)
   {
      test_ = "Row-major/row-major HermitianMatrix sparse matrix multiplication assignment (non-Hermitian)";

      blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 4UL );
      mat(0,1) = cplx(-2,-2);
      mat(0,2) = cplx( 6, 1);
      mat(1,1) = cplx( 3, 0);
      mat(2,0) = cplx( 6, 3);

      HT herm( 3UL );
      herm(0,0) = cplx( 1,0);
      herm(0,1) = cplx(-4,0);
      herm(0,2) = cplx( 7,0);
      herm(1,1) = cplx( 2,0);
      herm(2,2) = cplx( 3,0);

      try {
         herm *= mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/column-major sparse matrix multiplication assignment (non-Hermitian)
   {
      test_ = "Row-major/column-major HermitianMatrix sparse matrix multiplication assignment (non-Hermitian)";

      blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 4UL );
      mat(0,1) = cplx(-2,-2);
      mat(0,2) = cplx( 6, 1);
      mat(1,1) = cplx( 3, 0);
      mat(2,0) = cplx( 6, 3);

      HT herm( 3UL );
      herm(0,0) = cplx( 1,0);
      herm(0,1) = cplx(-4,0);
      herm(0,2) = cplx( 7,0);
      herm(1,1) = cplx( 2,0);
      herm(2,2) = cplx( 3,0);

      try {
         herm *= mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Row-major/row-major sparse matrix multiplication assignment (HermitianMatrix)
   {
      test_ = "Row-major/row-major HermitianMatrix sparse matrix multiplication assignment (HermitianMatrix)";

      blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > herm1( 3UL, 3UL );
      herm1(0,0) = cplx(2,0);
      herm1(1,1) = cplx(2,0);
      herm1(2,2) = cplx(2,0);

      HT herm2( 3UL );
      herm2(0,0) = cplx( 1, 0);
      herm2(0,1) = cplx(-4,-1);
      herm2(0,2) = cplx( 7, 3);
      herm2(1,1) = cplx( 2, 0);
      herm2(2,2) = cplx( 3, 0);

      herm2 *= herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );
      checkNonZeros( herm2, 0UL, 3UL );
      checkNonZeros( herm2, 1UL, 2UL );
      checkNonZeros( herm2, 2UL, 2UL );

      if( herm2(0,0) != cplx( 2, 0) || herm2(0,1) != cplx(-8,-2) || herm2(0,2) != cplx(14,6) ||
          herm2(1,0) != cplx(-8, 2) || herm2(1,1) != cplx( 4, 0) || herm2(1,2) != cplx( 0,0) ||
          herm2(2,0) != cplx(14,-6) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx( 6,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n(  2 -8 14 )\n"
                                     "( -8  4  0 )\n"
                                     "( 14  0  6 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Row-major/column-major sparse matrix multiplication assignment (HermitianMatrix)
   {
      test_ = "Row-major/column-major HermitianMatrix sparse matrix multiplication assignment (HermitianMatrix)";

      blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > herm1( 3UL, 3UL );
      herm1(0,0) = cplx(2,0);
      herm1(1,1) = cplx(2,0);
      herm1(2,2) = cplx(2,0);

      HT herm2( 3UL );
      herm2(0,0) = cplx( 1, 0);
      herm2(0,1) = cplx(-4,-1);
      herm2(0,2) = cplx( 7, 3);
      herm2(1,1) = cplx( 2, 0);
      herm2(2,2) = cplx( 3, 0);

      herm2 *= herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );
      checkNonZeros( herm2, 0UL, 3UL );
      checkNonZeros( herm2, 1UL, 2UL );
      checkNonZeros( herm2, 2UL, 2UL );

      if( herm2(0,0) != cplx( 2, 0) || herm2(0,1) != cplx(-8,-2) || herm2(0,2) != cplx(14,6) ||
          herm2(1,0) != cplx(-8, 2) || herm2(1,1) != cplx( 4, 0) || herm2(1,2) != cplx( 0,0) ||
          herm2(2,0) != cplx(14,-6) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx( 6,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n(  2 -8 14 )\n"
                                     "( -8  4  0 )\n"
                                     "( 14  0  6 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major dense matrix multiplication assignment
   //=====================================================================================

   // Column-major/row-major dense matrix multiplication assignment (Hermitian)
   {
      test_ = "Column-major/row-major HermitianMatrix dense matrix multiplication assignment (Hermitian)";

      blaze::DynamicMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,0) = cplx(2,0);
      mat(1,1) = cplx(2,0);
      mat(2,2) = cplx(2,0);

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      herm *= mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 2UL );

      if( herm(0,0) != cplx( 2, 0) || herm(0,1) != cplx(-8,-2) || herm(0,2) != cplx(14,6) ||
          herm(1,0) != cplx(-8, 2) || herm(1,1) != cplx( 4, 0) || herm(1,2) != cplx( 0,0) ||
          herm(2,0) != cplx(14,-6) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx( 6,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n(  2 -8 14 )\n"
                                     "( -8  4  0 )\n"
                                     "( 14  0  6 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Column-major/column-major dense matrix multiplication assignment (Hermitian)
   {
      test_ = "Column-major/column-major HermitianMatrix dense matrix multiplication assignment (Hermitian)";

      blaze::DynamicMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,0) = cplx(2,0);
      mat(1,1) = cplx(2,0);
      mat(2,2) = cplx(2,0);

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      herm *= mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 2UL );

      if( herm(0,0) != cplx( 2, 0) || herm(0,1) != cplx(-8,-2) || herm(0,2) != cplx(14,6) ||
          herm(1,0) != cplx(-8, 2) || herm(1,1) != cplx( 4, 0) || herm(1,2) != cplx( 0,0) ||
          herm(2,0) != cplx(14,-6) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx( 6,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n(  2 -8 14 )\n"
                                     "( -8  4  0 )\n"
                                     "( 14  0  6 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Column-major/row-major dense matrix multiplication assignment (non-Hermitian)
   {
      test_ = "Column-major/row-major HermitianMatrix dense matrix multiplication assignment (non-Hermitian)";

      blaze::DynamicMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx(-2,-2);
      mat(0,2) = cplx( 6, 1);
      mat(1,1) = cplx( 3, 0);
      mat(2,0) = cplx( 6, 3);

      OHT herm( 3UL );
      herm(0,0) = cplx( 1,0);
      herm(0,1) = cplx(-4,0);
      herm(0,2) = cplx( 7,0);
      herm(1,1) = cplx( 2,0);
      herm(2,2) = cplx( 3,0);

      try {
         herm *= mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/column-major dense matrix multiplication assignment (non-Hermitian)
   {
      test_ = "Column-major/column-major HermitianMatrix dense matrix multiplication assignment (non-Hermitian)";

      blaze::DynamicMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, cplx(0,0) );
      mat(0,1) = cplx(-2,-2);
      mat(0,2) = cplx( 6, 1);
      mat(1,1) = cplx( 3, 0);
      mat(2,0) = cplx( 6, 3);

      OHT herm( 3UL );
      herm(0,0) = cplx( 1,0);
      herm(0,1) = cplx(-4,0);
      herm(0,2) = cplx( 7,0);
      herm(1,1) = cplx( 2,0);
      herm(2,2) = cplx( 3,0);

      try {
         herm *= mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/row-major dense matrix multiplication assignment (HermitianMatrix)
   {
      test_ = "Column-major/row-major HermitianMatrix dense matrix multiplication assignment (HermitianMatrix)";

      HT herm1( 3UL );
      herm1(0,0) = cplx(2,0);
      herm1(1,1) = cplx(2,0);
      herm1(2,2) = cplx(2,0);

      OHT herm2( 3UL );
      herm2(0,0) = cplx( 1, 0);
      herm2(0,1) = cplx(-4,-1);
      herm2(0,2) = cplx( 7, 3);
      herm2(1,1) = cplx( 2, 0);
      herm2(2,2) = cplx( 3, 0);

      herm2 *= herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );
      checkNonZeros( herm2, 0UL, 3UL );
      checkNonZeros( herm2, 1UL, 2UL );
      checkNonZeros( herm2, 2UL, 2UL );

      if( herm2(0,0) != cplx( 2, 0) || herm2(0,1) != cplx(-8,-2) || herm2(0,2) != cplx(14,6) ||
          herm2(1,0) != cplx(-8, 2) || herm2(1,1) != cplx( 4, 0) || herm2(1,2) != cplx( 0,0) ||
          herm2(2,0) != cplx(14,-6) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx( 6,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n(  2 -8 14 )\n"
                                     "( -8  4  0 )\n"
                                     "( 14  0  6 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Column-major/column-major dense matrix multiplication assignment (HermitianMatrix)
   {
      test_ = "Column-major/column-major HermitianMatrix dense matrix multiplication assignment (HermitianMatrix)";

      OHT herm1( 3UL );
      herm1(0,0) = cplx(2,0);
      herm1(1,1) = cplx(2,0);
      herm1(2,2) = cplx(2,0);

      OHT herm2( 3UL );
      herm2(0,0) = cplx( 1, 0);
      herm2(0,1) = cplx(-4,-1);
      herm2(0,2) = cplx( 7, 3);
      herm2(1,1) = cplx( 2, 0);
      herm2(2,2) = cplx( 3, 0);

      herm2 *= herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );
      checkNonZeros( herm2, 0UL, 3UL );
      checkNonZeros( herm2, 1UL, 2UL );
      checkNonZeros( herm2, 2UL, 2UL );

      if( herm2(0,0) != cplx( 2, 0) || herm2(0,1) != cplx(-8,-2) || herm2(0,2) != cplx(14,6) ||
          herm2(1,0) != cplx(-8, 2) || herm2(1,1) != cplx( 4, 0) || herm2(1,2) != cplx( 0,0) ||
          herm2(2,0) != cplx(14,-6) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx( 6,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n(  2 -8 14 )\n"
                                     "( -8  4  0 )\n"
                                     "( 14  0  6 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major sparse matrix multiplication assignment
   //=====================================================================================

   // Column-major/row-major sparse matrix multiplication assignment (Hermitian)
   {
      test_ = "Column-major/row-major HermitianMatrix sparse matrix multiplication assignment (Hermitian)";

      blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 4UL );
      mat(0,0) = cplx(2,0);
      mat(1,1) = cplx(2,0);
      mat(2,2) = cplx(2,0);
      mat.insert( 1UL, 2UL, cplx(0,0) );

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      herm *= mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 2UL );

      if( herm(0,0) != cplx( 2, 0) || herm(0,1) != cplx(-8,-2) || herm(0,2) != cplx(14,6) ||
          herm(1,0) != cplx(-8, 2) || herm(1,1) != cplx( 4, 0) || herm(1,2) != cplx( 0,0) ||
          herm(2,0) != cplx(14,-6) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx( 6,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n(  2 -8 14 )\n"
                                     "( -8  4  0 )\n"
                                     "( 14  0  6 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Column-major/column-major sparse matrix multiplication assignment (Hermitian)
   {
      test_ = "Column-major/column-major HermitianMatrix sparse matrix multiplication assignment (Hermitian)";

      blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 4UL );
      mat(0,0) = cplx(2,0);
      mat(1,1) = cplx(2,0);
      mat(2,2) = cplx(2,0);
      mat.insert( 1UL, 2UL, cplx(0,0) );

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      herm *= mat;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 2UL );

      if( herm(0,0) != cplx( 2, 0) || herm(0,1) != cplx(-8,-2) || herm(0,2) != cplx(14,6) ||
          herm(1,0) != cplx(-8, 2) || herm(1,1) != cplx( 4, 0) || herm(1,2) != cplx( 0,0) ||
          herm(2,0) != cplx(14,-6) || herm(2,1) != cplx( 0, 0) || herm(2,2) != cplx( 6,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n(  2 -8 14 )\n"
                                     "( -8  4  0 )\n"
                                     "( 14  0  6 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Column-major/row-major sparse matrix multiplication assignment (non-Hermitian)
   {
      test_ = "Column-major/row-major HermitianMatrix sparse matrix multiplication assignment (non-Hermitian)";

      blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 4UL );
      mat(0,1) = cplx(-2,-2);
      mat(0,2) = cplx( 6, 1);
      mat(1,1) = cplx( 3, 0);
      mat(2,0) = cplx( 6, 3);

      OHT herm( 3UL );
      herm(0,0) = cplx( 1,0);
      herm(0,1) = cplx(-4,0);
      herm(0,2) = cplx( 7,0);
      herm(1,1) = cplx( 2,0);
      herm(2,2) = cplx( 3,0);

      try {
         herm *= mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/column-major sparse matrix multiplication assignment (non-Hermitian)
   {
      test_ = "Column-major/column-major HermitianMatrix sparse matrix multiplication assignment (non-Hermitian)";

      blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 4UL );
      mat(0,1) = cplx(-2,-2);
      mat(0,2) = cplx( 6, 1);
      mat(1,1) = cplx( 3, 0);
      mat(2,0) = cplx( 6, 3);

      OHT herm( 3UL );
      herm(0,0) = cplx( 1,0);
      herm(0,1) = cplx(-4,0);
      herm(0,2) = cplx( 7,0);
      herm(1,1) = cplx( 2,0);
      herm(2,2) = cplx( 3,0);

      try {
         herm *= mat;

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment of non-Hermitian row-major matrix succeeded\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }

   // Column-major/row-major sparse matrix multiplication assignment (HermitianMatrix)
   {
      test_ = "Column-major/row-major HermitianMatrix sparse matrix multiplication assignment (HermitianMatrix)";

      blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > herm1( 3UL, 3UL );
      herm1(0,0) = cplx(2,0);
      herm1(1,1) = cplx(2,0);
      herm1(2,2) = cplx(2,0);

      OHT herm2( 3UL );
      herm2(0,0) = cplx( 1, 0);
      herm2(0,1) = cplx(-4,-1);
      herm2(0,2) = cplx( 7, 3);
      herm2(1,1) = cplx( 2, 0);
      herm2(2,2) = cplx( 3, 0);

      herm2 *= herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );
      checkNonZeros( herm2, 0UL, 3UL );
      checkNonZeros( herm2, 1UL, 2UL );
      checkNonZeros( herm2, 2UL, 2UL );

      if( herm2(0,0) != cplx( 2, 0) || herm2(0,1) != cplx(-8,-2) || herm2(0,2) != cplx(14,6) ||
          herm2(1,0) != cplx(-8, 2) || herm2(1,1) != cplx( 4, 0) || herm2(1,2) != cplx( 0,0) ||
          herm2(2,0) != cplx(14,-6) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx( 6,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n(  2 -8 14 )\n"
                                     "( -8  4  0 )\n"
                                     "( 14  0  6 )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Column-major/column-major sparse matrix multiplication assignment (HermitianMatrix)
   {
      test_ = "Column-major/column-major HermitianMatrix sparse matrix multiplication assignment (HermitianMatrix)";

      blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > herm1( 3UL, 3UL );
      herm1(0,0) = cplx(2,0);
      herm1(1,1) = cplx(2,0);
      herm1(2,2) = cplx(2,0);

      OHT herm2( 3UL );
      herm2(0,0) = cplx( 1, 0);
      herm2(0,1) = cplx(-4,-1);
      herm2(0,2) = cplx( 7, 3);
      herm2(1,1) = cplx( 2, 0);
      herm2(2,2) = cplx( 3, 0);

      herm2 *= herm1;

      checkRows    ( herm2, 3UL );
      checkColumns ( herm2, 3UL );
      checkCapacity( herm2, 9UL );
      checkNonZeros( herm2, 7UL );
      checkNonZeros( herm2, 0UL, 3UL );
      checkNonZeros( herm2, 1UL, 2UL );
      checkNonZeros( herm2, 2UL, 2UL );

      if( herm2(0,0) != cplx( 2, 0) || herm2(0,1) != cplx(-8,-2) || herm2(0,2) != cplx(14,6) ||
          herm2(1,0) != cplx(-8, 2) || herm2(1,1) != cplx( 4, 0) || herm2(1,2) != cplx( 0,0) ||
          herm2(2,0) != cplx(14,-6) || herm2(2,1) != cplx( 0, 0) || herm2(2,2) != cplx( 6,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n(  2 -8 14 )\n"
                                     "( -8  4  0 )\n"
                                     "( 14  0  6 )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of all HermitianMatrix (self-)scaling operations.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of all available ways to scale an instance of the HermitianMatrix
// specialization. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void DenseComplexTest::testScaling()
{
   //=====================================================================================
   // Row-major self-scaling (M*=s)
   //=====================================================================================

   {
      test_ = "Row-major self-scaling (M*=s)";

      HT herm( 3UL );
      herm(1,2) = cplx( 1,-2);
      herm(2,0) = cplx(-2, 0);
      herm(2,2) = cplx( 3, 0);

      herm *= 2;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 5UL );
      checkNonZeros( herm, 0UL, 1UL );
      checkNonZeros( herm, 1UL, 1UL );
      checkNonZeros( herm, 2UL, 3UL );

      if( herm(0,0) != cplx( 0,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(-4, 0) ||
          herm(1,0) != cplx( 0,0) || herm(1,1) != cplx(0,0) || herm(1,2) != cplx( 2,-4) ||
          herm(2,0) != cplx(-4,0) || herm(2,1) != cplx(2,4) || herm(2,2) != cplx( 6, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 0,0) (0,0) (-4, 0) )\n"
                                     "( ( 0,0) (0,0) ( 2,-4) )\n"
                                     "( (-4,0) (2,4) ( 6, 0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major self-scaling (M=M*s)
   //=====================================================================================

   {
      test_ = "Row-major self-scaling (M=M*s)";

      HT herm( 3UL );
      herm(1,2) = cplx( 1,-2);
      herm(2,0) = cplx(-2, 0);
      herm(2,2) = cplx( 3, 0);

      herm = herm * 2;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 5UL );
      checkNonZeros( herm, 0UL, 1UL );
      checkNonZeros( herm, 1UL, 1UL );
      checkNonZeros( herm, 2UL, 3UL );

      if( herm(0,0) != cplx( 0,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(-4, 0) ||
          herm(1,0) != cplx( 0,0) || herm(1,1) != cplx(0,0) || herm(1,2) != cplx( 2,-4) ||
          herm(2,0) != cplx(-4,0) || herm(2,1) != cplx(2,4) || herm(2,2) != cplx( 6, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 0,0) (0,0) (-4, 0) )\n"
                                     "( ( 0,0) (0,0) ( 2,-4) )\n"
                                     "( (-4,0) (2,4) ( 6, 0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major self-scaling (M=s*M)
   //=====================================================================================

   {
      test_ = "Row-major self-scaling (M=s*M)";

      HT herm( 3UL );
      herm(1,2) = cplx( 1,-2);
      herm(2,0) = cplx(-2, 0);
      herm(2,2) = cplx( 3, 0);

      herm = 2 * herm;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 5UL );
      checkNonZeros( herm, 0UL, 1UL );
      checkNonZeros( herm, 1UL, 1UL );
      checkNonZeros( herm, 2UL, 3UL );

      if( herm(0,0) != cplx( 0,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(-4, 0) ||
          herm(1,0) != cplx( 0,0) || herm(1,1) != cplx(0,0) || herm(1,2) != cplx( 2,-4) ||
          herm(2,0) != cplx(-4,0) || herm(2,1) != cplx(2,4) || herm(2,2) != cplx( 6, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 0,0) (0,0) (-4, 0) )\n"
                                     "( ( 0,0) (0,0) ( 2,-4) )\n"
                                     "( (-4,0) (2,4) ( 6, 0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major self-scaling (M/=s)
   //=====================================================================================

   {
      test_ = "Row-major self-scaling (M/=s)";

      HT herm( 3UL );
      herm(1,2) = cplx( 2,-4);
      herm(2,0) = cplx(-4, 0);
      herm(2,2) = cplx( 6, 0);

      herm /= 2;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 5UL );
      checkNonZeros( herm, 0UL, 1UL );
      checkNonZeros( herm, 1UL, 1UL );
      checkNonZeros( herm, 2UL, 3UL );

      if( herm(0,0) != cplx( 0,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(-2, 0) ||
          herm(1,0) != cplx( 0,0) || herm(1,1) != cplx(0,0) || herm(1,2) != cplx( 1,-2) ||
          herm(2,0) != cplx(-2,0) || herm(2,1) != cplx(1,2) || herm(2,2) != cplx( 3, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 0,0) (0,0) (-2, 0) )\n"
                                     "( ( 0,0) (0,0) ( 1,-2) )\n"
                                     "( (-2,0) (1,2) ( 3, 0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major self-scaling (M=M/s)
   //=====================================================================================

   {
      test_ = "Row-major self-scaling (M=M/s)";

      HT herm( 3UL );
      herm(1,2) = cplx( 2,-4);
      herm(2,0) = cplx(-4, 0);
      herm(2,2) = cplx( 6, 0);

      herm = herm / 2;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 5UL );
      checkNonZeros( herm, 0UL, 1UL );
      checkNonZeros( herm, 1UL, 1UL );
      checkNonZeros( herm, 2UL, 3UL );

      if( herm(0,0) != cplx( 0,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(-2, 0) ||
          herm(1,0) != cplx( 0,0) || herm(1,1) != cplx(0,0) || herm(1,2) != cplx( 1,-2) ||
          herm(2,0) != cplx(-2,0) || herm(2,1) != cplx(1,2) || herm(2,2) != cplx( 3, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 0,0) (0,0) (-2, 0) )\n"
                                     "( ( 0,0) (0,0) ( 1,-2) )\n"
                                     "( (-2,0) (1,2) ( 3, 0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major HermitianMatrix::scale()
   //=====================================================================================

   {
      test_ = "Row-major HermitianMatrix::scale()";

      // Initialization check
      HT herm( 3UL );
      herm(1,2) = cplx( 1,-2);
      herm(2,0) = cplx(-2, 0);
      herm(2,2) = cplx( 3, 0);

      herm.scale( 2 );

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 5UL );
      checkNonZeros( herm, 0UL, 1UL );
      checkNonZeros( herm, 1UL, 1UL );
      checkNonZeros( herm, 2UL, 3UL );

      if( herm(0,0) != cplx( 0,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(-4, 0) ||
          herm(1,0) != cplx( 0,0) || herm(1,1) != cplx(0,0) || herm(1,2) != cplx( 2,-4) ||
          herm(2,0) != cplx(-4,0) || herm(2,1) != cplx(2,4) || herm(2,2) != cplx( 6, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 0,0) (0,0) (-4, 0) )\n"
                                     "( ( 0,0) (0,0) ( 2,-4) )\n"
                                     "( (-4,0) (2,4) ( 6, 0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major HermitianMatrix::scale() (complex)";

      // Initialization check
      HT herm( 3UL );
      herm(1,2) = cplx( 1,-2);
      herm(2,0) = cplx(-2, 0);
      herm(2,2) = cplx( 3, 0);

      herm.scale( cplx(3,0) );

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 5UL );
      checkNonZeros( herm, 0UL, 1UL );
      checkNonZeros( herm, 1UL, 1UL );
      checkNonZeros( herm, 2UL, 3UL );

      if( herm(0,0) != cplx( 0,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(-6, 0) ||
          herm(1,0) != cplx( 0,0) || herm(1,1) != cplx(0,0) || herm(1,2) != cplx( 3,-6) ||
          herm(2,0) != cplx(-6,0) || herm(2,1) != cplx(3,6) || herm(2,2) != cplx( 9, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 0,0) (0,0) (-6, 0) )\n"
                                     "( ( 0,0) (0,0) ( 3,-6) )\n"
                                     "( (-6,0) (3,6) ( 9, 0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major self-scaling (M*=s)
   //=====================================================================================

   {
      test_ = "Column-major self-scaling (M*=s)";

      OHT herm( 3UL );
      herm(1,2) = cplx( 1,-2);
      herm(2,0) = cplx(-2, 0);
      herm(2,2) = cplx( 3, 0);

      herm *= 2;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 5UL );
      checkNonZeros( herm, 0UL, 1UL );
      checkNonZeros( herm, 1UL, 1UL );
      checkNonZeros( herm, 2UL, 3UL );

      if( herm(0,0) != cplx( 0,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(-4, 0) ||
          herm(1,0) != cplx( 0,0) || herm(1,1) != cplx(0,0) || herm(1,2) != cplx( 2,-4) ||
          herm(2,0) != cplx(-4,0) || herm(2,1) != cplx(2,4) || herm(2,2) != cplx( 6, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 0,0) (0,0) (-4, 0) )\n"
                                     "( ( 0,0) (0,0) ( 2,-4) )\n"
                                     "( (-4,0) (2,4) ( 6, 0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major self-scaling (M=M*s)
   //=====================================================================================

   {
      test_ = "Column-major self-scaling (M=M*s)";

      OHT herm( 3UL );
      herm(1,2) = cplx( 1,-2);
      herm(2,0) = cplx(-2, 0);
      herm(2,2) = cplx( 3, 0);

      herm = herm * 2;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 5UL );
      checkNonZeros( herm, 0UL, 1UL );
      checkNonZeros( herm, 1UL, 1UL );
      checkNonZeros( herm, 2UL, 3UL );

      if( herm(0,0) != cplx( 0,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(-4, 0) ||
          herm(1,0) != cplx( 0,0) || herm(1,1) != cplx(0,0) || herm(1,2) != cplx( 2,-4) ||
          herm(2,0) != cplx(-4,0) || herm(2,1) != cplx(2,4) || herm(2,2) != cplx( 6, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 0,0) (0,0) (-4, 0) )\n"
                                     "( ( 0,0) (0,0) ( 2,-4) )\n"
                                     "( (-4,0) (2,4) ( 6, 0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major self-scaling (M=s*M)
   //=====================================================================================

   {
      test_ = "Column-major self-scaling (M=s*M)";

      OHT herm( 3UL );
      herm(1,2) = cplx( 1,-2);
      herm(2,0) = cplx(-2, 0);
      herm(2,2) = cplx( 3, 0);

      herm = 2 * herm;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 5UL );
      checkNonZeros( herm, 0UL, 1UL );
      checkNonZeros( herm, 1UL, 1UL );
      checkNonZeros( herm, 2UL, 3UL );

      if( herm(0,0) != cplx( 0,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(-4, 0) ||
          herm(1,0) != cplx( 0,0) || herm(1,1) != cplx(0,0) || herm(1,2) != cplx( 2,-4) ||
          herm(2,0) != cplx(-4,0) || herm(2,1) != cplx(2,4) || herm(2,2) != cplx( 6, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 0,0) (0,0) (-4, 0) )\n"
                                     "( ( 0,0) (0,0) ( 2,-4) )\n"
                                     "( (-4,0) (2,4) ( 6, 0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major self-scaling (M/=s)
   //=====================================================================================

   {
      test_ = "Column-major self-scaling (M/=s)";

      OHT herm( 3UL );
      herm(1,2) = cplx( 2,-4);
      herm(2,0) = cplx(-4, 0);
      herm(2,2) = cplx( 6, 0);

      herm /= 2;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 5UL );
      checkNonZeros( herm, 0UL, 1UL );
      checkNonZeros( herm, 1UL, 1UL );
      checkNonZeros( herm, 2UL, 3UL );

      if( herm(0,0) != cplx( 0,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(-2, 0) ||
          herm(1,0) != cplx( 0,0) || herm(1,1) != cplx(0,0) || herm(1,2) != cplx( 1,-2) ||
          herm(2,0) != cplx(-2,0) || herm(2,1) != cplx(1,2) || herm(2,2) != cplx( 3, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 0,0) (0,0) (-2, 0) )\n"
                                     "( ( 0,0) (0,0) ( 1,-2) )\n"
                                     "( (-2,0) (1,2) ( 3, 0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major self-scaling (M=M/s)
   //=====================================================================================

   {
      test_ = "Column-major self-scaling (M=M/s)";

      OHT herm( 3UL );
      herm(1,2) = cplx( 2,-4);
      herm(2,0) = cplx(-4, 0);
      herm(2,2) = cplx( 6, 0);

      herm = herm / 2;

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 5UL );
      checkNonZeros( herm, 0UL, 1UL );
      checkNonZeros( herm, 1UL, 1UL );
      checkNonZeros( herm, 2UL, 3UL );

      if( herm(0,0) != cplx( 0,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(-2, 0) ||
          herm(1,0) != cplx( 0,0) || herm(1,1) != cplx(0,0) || herm(1,2) != cplx( 1,-2) ||
          herm(2,0) != cplx(-2,0) || herm(2,1) != cplx(1,2) || herm(2,2) != cplx( 3, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 0,0) (0,0) (-2, 0) )\n"
                                     "( ( 0,0) (0,0) ( 1,-2) )\n"
                                     "( (-2,0) (1,2) ( 3, 0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major HermitianMatrix::scale()
   //=====================================================================================

   {
      test_ = "Column-major HermitianMatrix::scale()";

      // Initialization check
      OHT herm( 3UL );
      herm(1,2) = cplx( 1,-2);
      herm(2,0) = cplx(-2, 0);
      herm(2,2) = cplx( 3, 0);

      herm.scale( 2 );

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 5UL );
      checkNonZeros( herm, 0UL, 1UL );
      checkNonZeros( herm, 1UL, 1UL );
      checkNonZeros( herm, 2UL, 3UL );

      if( herm(0,0) != cplx( 0,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(-4, 0) ||
          herm(1,0) != cplx( 0,0) || herm(1,1) != cplx(0,0) || herm(1,2) != cplx( 2,-4) ||
          herm(2,0) != cplx(-4,0) || herm(2,1) != cplx(2,4) || herm(2,2) != cplx( 6, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 0,0) (0,0) (-4, 0) )\n"
                                     "( ( 0,0) (0,0) ( 2,-4) )\n"
                                     "( (-4,0) (2,4) ( 6, 0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major HermitianMatrix::scale() (complex)";

      // Initialization check
      OHT herm( 3UL );
      herm(1,2) = cplx( 1,-2);
      herm(2,0) = cplx(-2, 0);
      herm(2,2) = cplx( 3, 0);

      herm.scale( cplx(3,0) );

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 5UL );
      checkNonZeros( herm, 0UL, 1UL );
      checkNonZeros( herm, 1UL, 1UL );
      checkNonZeros( herm, 2UL, 3UL );

      if( herm(0,0) != cplx( 0,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(-6, 0) ||
          herm(1,0) != cplx( 0,0) || herm(1,1) != cplx(0,0) || herm(1,2) != cplx( 3,-6) ||
          herm(2,0) != cplx(-6,0) || herm(2,1) != cplx(3,6) || herm(2,2) != cplx( 9, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 0,0) (0,0) (-6, 0) )\n"
                                     "( ( 0,0) (0,0) ( 3,-6) )\n"
                                     "( (-6,0) (3,6) ( 9, 0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the HermitianMatrix function call operator.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of adding and accessing elements via the function call operator
// of the HermitianMatrix specialization. In case an error is detected, a \a std::runtime_error
// exception is thrown.
*/
void DenseComplexTest::testFunctionCall()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major HermitianMatrix::operator()";

      // Good cases
      {
         HT herm( 3UL );

         // Writing the element (1,1)
         herm(1,1) = cplx(1,0);

         checkRows    ( herm, 3UL );
         checkColumns ( herm, 3UL );
         checkCapacity( herm, 9UL );
         checkNonZeros( herm, 1UL );
         checkNonZeros( herm, 0UL, 0UL );
         checkNonZeros( herm, 1UL, 1UL );
         checkNonZeros( herm, 2UL, 0UL );

         if( herm(0,0) != cplx(0,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(0,0) ||
             herm(1,0) != cplx(0,0) || herm(1,1) != cplx(1,0) || herm(1,2) != cplx(0,0) ||
             herm(2,0) != cplx(0,0) || herm(2,1) != cplx(0,0) || herm(2,2) != cplx(0,0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Function call operator failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( (0,0) (0,0) (0,0) )\n"
                                        "( (0,0) (1,0) (0,0) )\n"
                                        "( (0,0) (0,0) (0,0) )\n";
            throw std::runtime_error( oss.str() );
         }

         // Writing the elements (2,1) and (1,2)
         herm(2,1) = cplx(2,2);

         checkRows    ( herm, 3UL );
         checkColumns ( herm, 3UL );
         checkCapacity( herm, 9UL );
         checkNonZeros( herm, 3UL );
         checkNonZeros( herm, 0UL, 0UL );
         checkNonZeros( herm, 1UL, 2UL );
         checkNonZeros( herm, 2UL, 1UL );

         if( herm(0,0) != cplx(0,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(0, 0) ||
             herm(1,0) != cplx(0,0) || herm(1,1) != cplx(1,0) || herm(1,2) != cplx(2,-2) ||
             herm(2,0) != cplx(0,0) || herm(2,1) != cplx(2,2) || herm(2,2) != cplx(0, 0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Function call operator failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( (0,0) (0,0) (0, 0) )\n"
                                        "( (0,0) (1,0) (2,-2) )\n"
                                        "( (0,0) (2,2) (0, 0) )\n";
            throw std::runtime_error( oss.str() );
         }

         // Writing the elements (0,2) and (2,0)
         herm(0,2) = herm(1,2);

         checkRows    ( herm, 3UL );
         checkColumns ( herm, 3UL );
         checkCapacity( herm, 9UL );
         checkNonZeros( herm, 5UL );
         checkNonZeros( herm, 0UL, 1UL );
         checkNonZeros( herm, 1UL, 2UL );
         checkNonZeros( herm, 2UL, 2UL );

         if( herm(0,0) != cplx(0,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(2,-2) ||
             herm(1,0) != cplx(0,0) || herm(1,1) != cplx(1,0) || herm(1,2) != cplx(2,-2) ||
             herm(2,0) != cplx(2,2) || herm(2,1) != cplx(2,2) || herm(2,2) != cplx(0, 0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Function call operator failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( (0,0) (0,0) (2,-2) )\n"
                                        "( (0,0) (1,0) (2,-2) )\n"
                                        "( (2,2) (2,2) (0, 0) )\n";
            throw std::runtime_error( oss.str() );
         }

         // Adding to the elements (1,2) and (2,1)
         herm(1,2) += cplx(3,3);

         checkRows    ( herm, 3UL );
         checkColumns ( herm, 3UL );
         checkCapacity( herm, 9UL );
         checkNonZeros( herm, 5UL );
         checkNonZeros( herm, 0UL, 1UL );
         checkNonZeros( herm, 1UL, 2UL );
         checkNonZeros( herm, 2UL, 2UL );

         if( herm(0,0) != cplx(0,0) || herm(0,1) != cplx(0, 0) || herm(0,2) != cplx(2,-2) ||
             herm(1,0) != cplx(0,0) || herm(1,1) != cplx(1, 0) || herm(1,2) != cplx(5, 1) ||
             herm(2,0) != cplx(2,2) || herm(2,1) != cplx(5,-1) || herm(2,2) != cplx(0, 0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Function call operator failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( (0,0) (0, 0) (2,-2) )\n"
                                        "( (0,0) (1, 0) (5, 1) )\n"
                                        "( (2,2) (5,-1) (0, 0) )\n";
            throw std::runtime_error( oss.str() );
         }

         // Subtracting from the elements (0,1) and (1,0)
         herm(0,1) -= cplx(4,4);

         checkRows    ( herm, 3UL );
         checkColumns ( herm, 3UL );
         checkCapacity( herm, 9UL );
         checkNonZeros( herm, 7UL );
         checkNonZeros( herm, 0UL, 2UL );
         checkNonZeros( herm, 1UL, 3UL );
         checkNonZeros( herm, 2UL, 2UL );

         if( herm(0,0) != cplx( 0,0) || herm(0,1) != cplx(-4,-4) || herm(0,2) != cplx(2,-2) ||
             herm(1,0) != cplx(-4,4) || herm(1,1) != cplx( 1, 0) || herm(1,2) != cplx(5, 1) ||
             herm(2,0) != cplx( 2,2) || herm(2,1) != cplx( 5,-1) || herm(2,2) != cplx(0, 0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Function call operator failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( ( 0,0) (-4,-4) (2,-2) )\n"
                                        "( (-4,4) ( 1, 0) (5, 1) )\n"
                                        "( ( 2,2) ( 5,-1) (0, 0) )\n";
            throw std::runtime_error( oss.str() );
         }

         // Multiplying the element (1,1)
         herm(2,0) *= cplx(-3,1);

         checkRows    ( herm, 3UL );
         checkColumns ( herm, 3UL );
         checkCapacity( herm, 9UL );
         checkNonZeros( herm, 7UL );
         checkNonZeros( herm, 0UL, 2UL );
         checkNonZeros( herm, 1UL, 3UL );
         checkNonZeros( herm, 2UL, 2UL );

         if( herm(0,0) != cplx( 0, 0) || herm(0,1) != cplx(-4,-4) || herm(0,2) != cplx(-8,4) ||
             herm(1,0) != cplx(-4, 4) || herm(1,1) != cplx( 1, 0) || herm(1,2) != cplx( 5,1) ||
             herm(2,0) != cplx(-8,-4) || herm(2,1) != cplx( 5,-1) || herm(2,2) != cplx( 0,0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Function call operator failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( ( 0, 0) (-4,-4) (-8,4) )\n"
                                        "( (-4, 4) ( 1, 0) ( 5,1) )\n"
                                        "( (-8,-4) ( 5,-1) ( 0,0) )\n";
            throw std::runtime_error( oss.str() );
         }

         // Dividing the elements (0,2) and (2,0)
         herm(1,0) /= 2;

         checkRows    ( herm, 3UL );
         checkColumns ( herm, 3UL );
         checkCapacity( herm, 9UL );
         checkNonZeros( herm, 7UL );
         checkNonZeros( herm, 0UL, 2UL );
         checkNonZeros( herm, 1UL, 3UL );
         checkNonZeros( herm, 2UL, 2UL );

         if( herm(0,0) != cplx( 0, 0) || herm(0,1) != cplx(-2,-2) || herm(0,2) != cplx(-8,4) ||
             herm(1,0) != cplx(-2, 2) || herm(1,1) != cplx( 1, 0) || herm(1,2) != cplx( 5,1) ||
             herm(2,0) != cplx(-8,-4) || herm(2,1) != cplx( 5,-1) || herm(2,2) != cplx( 0,0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Function call operator failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( ( 0, 0) (-2,-2) (-8,4) )\n"
                                        "( (-2, 2) ( 1, 0) ( 5,1) )\n"
                                        "( (-8,-4) ( 5,-1) ( 0,0) )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Failure cases
      {
         HT herm( 3UL );

         // Trying to write the diagonal element (0,0)
         try {
            herm(0,0) = cplx(5,5);

            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment to diagonal matrix element succeeded\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n";
            throw std::runtime_error( oss.str() );
         }
         catch( std::invalid_argument& ) {}

         // Trying to add to the diagonal element (1,1)
         try {
            herm(1,1) += cplx(5,5);

            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Addition assignment to diagonal matrix element succeeded\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n";
            throw std::runtime_error( oss.str() );
         }
         catch( std::invalid_argument& ) {}

         // Trying to subtract from the diagonal element (2,2)
         try {
            herm(2,2) -= cplx(5,5);

            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Subtraction assignment to diagonal matrix element succeeded\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n";
            throw std::runtime_error( oss.str() );
         }
         catch( std::invalid_argument& ) {}

         // Trying to multiply the diagonal element (1,1)
         try {
            herm(1,1) *= cplx(5,5);

            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Multiplication assignment to diagonal matrix element succeeded\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n";
            throw std::runtime_error( oss.str() );
         }
         catch( std::invalid_argument& ) {}

         // Trying to divide the diagonal element (1,1)
         try {
            herm(1,1) /= cplx(5,5);

            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Division assignment to diagonal matrix element succeeded\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n";
            throw std::runtime_error( oss.str() );
         }
         catch( std::invalid_argument& ) {}
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major HermitianMatrix::operator()";

      // Good cases
      {
         OHT herm( 3UL );

         // Writing the element (1,1)
         herm(1,1) = cplx(1,0);

         checkRows    ( herm, 3UL );
         checkColumns ( herm, 3UL );
         checkCapacity( herm, 9UL );
         checkNonZeros( herm, 1UL );
         checkNonZeros( herm, 0UL, 0UL );
         checkNonZeros( herm, 1UL, 1UL );
         checkNonZeros( herm, 2UL, 0UL );

         if( herm(0,0) != cplx(0,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(0,0) ||
             herm(1,0) != cplx(0,0) || herm(1,1) != cplx(1,0) || herm(1,2) != cplx(0,0) ||
             herm(2,0) != cplx(0,0) || herm(2,1) != cplx(0,0) || herm(2,2) != cplx(0,0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Function call operator failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( (0,0) (0,0) (0,0) )\n"
                                        "( (0,0) (1,0) (0,0) )\n"
                                        "( (0,0) (0,0) (0,0) )\n";
            throw std::runtime_error( oss.str() );
         }

         // Writing the elements (2,1) and (1,2)
         herm(2,1) = cplx(2,2);

         checkRows    ( herm, 3UL );
         checkColumns ( herm, 3UL );
         checkCapacity( herm, 9UL );
         checkNonZeros( herm, 3UL );
         checkNonZeros( herm, 0UL, 0UL );
         checkNonZeros( herm, 1UL, 2UL );
         checkNonZeros( herm, 2UL, 1UL );

         if( herm(0,0) != cplx(0,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(0, 0) ||
             herm(1,0) != cplx(0,0) || herm(1,1) != cplx(1,0) || herm(1,2) != cplx(2,-2) ||
             herm(2,0) != cplx(0,0) || herm(2,1) != cplx(2,2) || herm(2,2) != cplx(0, 0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Function call operator failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( (0,0) (0,0) (0, 0) )\n"
                                        "( (0,0) (1,0) (2,-2) )\n"
                                        "( (0,0) (2,2) (0, 0) )\n";
            throw std::runtime_error( oss.str() );
         }

         // Writing the elements (0,2) and (2,0)
         herm(0,2) = herm(1,2);

         checkRows    ( herm, 3UL );
         checkColumns ( herm, 3UL );
         checkCapacity( herm, 9UL );
         checkNonZeros( herm, 5UL );
         checkNonZeros( herm, 0UL, 1UL );
         checkNonZeros( herm, 1UL, 2UL );
         checkNonZeros( herm, 2UL, 2UL );

         if( herm(0,0) != cplx(0,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(2,-2) ||
             herm(1,0) != cplx(0,0) || herm(1,1) != cplx(1,0) || herm(1,2) != cplx(2,-2) ||
             herm(2,0) != cplx(2,2) || herm(2,1) != cplx(2,2) || herm(2,2) != cplx(0, 0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Function call operator failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( (0,0) (0,0) (2,-2) )\n"
                                        "( (0,0) (1,0) (2,-2) )\n"
                                        "( (2,2) (2,2) (0, 0) )\n";
            throw std::runtime_error( oss.str() );
         }

         // Adding to the elements (1,2) and (2,1)
         herm(1,2) += cplx(3,3);

         checkRows    ( herm, 3UL );
         checkColumns ( herm, 3UL );
         checkCapacity( herm, 9UL );
         checkNonZeros( herm, 5UL );
         checkNonZeros( herm, 0UL, 1UL );
         checkNonZeros( herm, 1UL, 2UL );
         checkNonZeros( herm, 2UL, 2UL );

         if( herm(0,0) != cplx(0,0) || herm(0,1) != cplx(0, 0) || herm(0,2) != cplx(2,-2) ||
             herm(1,0) != cplx(0,0) || herm(1,1) != cplx(1, 0) || herm(1,2) != cplx(5, 1) ||
             herm(2,0) != cplx(2,2) || herm(2,1) != cplx(5,-1) || herm(2,2) != cplx(0, 0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Function call operator failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( (0,0) (0, 0) (2,-2) )\n"
                                        "( (0,0) (1, 0) (5, 1) )\n"
                                        "( (2,2) (5,-1) (0, 0) )\n";
            throw std::runtime_error( oss.str() );
         }

         // Subtracting from the elements (0,1) and (1,0)
         herm(0,1) -= cplx(4,4);

         checkRows    ( herm, 3UL );
         checkColumns ( herm, 3UL );
         checkCapacity( herm, 9UL );
         checkNonZeros( herm, 7UL );
         checkNonZeros( herm, 0UL, 2UL );
         checkNonZeros( herm, 1UL, 3UL );
         checkNonZeros( herm, 2UL, 2UL );

         if( herm(0,0) != cplx( 0,0) || herm(0,1) != cplx(-4,-4) || herm(0,2) != cplx(2,-2) ||
             herm(1,0) != cplx(-4,4) || herm(1,1) != cplx( 1, 0) || herm(1,2) != cplx(5, 1) ||
             herm(2,0) != cplx( 2,2) || herm(2,1) != cplx( 5,-1) || herm(2,2) != cplx(0, 0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Function call operator failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( ( 0,0) (-4,-4) (2,-2) )\n"
                                        "( (-4,4) ( 1, 0) (5, 1) )\n"
                                        "( ( 2,2) ( 5,-1) (0, 0) )\n";
            throw std::runtime_error( oss.str() );
         }

         // Multiplying the element (1,1)
         herm(2,0) *= cplx(-3,1);

         checkRows    ( herm, 3UL );
         checkColumns ( herm, 3UL );
         checkCapacity( herm, 9UL );
         checkNonZeros( herm, 7UL );
         checkNonZeros( herm, 0UL, 2UL );
         checkNonZeros( herm, 1UL, 3UL );
         checkNonZeros( herm, 2UL, 2UL );

         if( herm(0,0) != cplx( 0, 0) || herm(0,1) != cplx(-4,-4) || herm(0,2) != cplx(-8,4) ||
             herm(1,0) != cplx(-4, 4) || herm(1,1) != cplx( 1, 0) || herm(1,2) != cplx( 5,1) ||
             herm(2,0) != cplx(-8,-4) || herm(2,1) != cplx( 5,-1) || herm(2,2) != cplx( 0,0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Function call operator failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( ( 0, 0) (-4,-4) (-8,4) )\n"
                                        "( (-4, 4) ( 1, 0) ( 5,1) )\n"
                                        "( (-8,-4) ( 5,-1) ( 0,0) )\n";
            throw std::runtime_error( oss.str() );
         }

         // Dividing the elements (0,2) and (2,0)
         herm(1,0) /= 2;

         checkRows    ( herm, 3UL );
         checkColumns ( herm, 3UL );
         checkCapacity( herm, 9UL );
         checkNonZeros( herm, 7UL );
         checkNonZeros( herm, 0UL, 2UL );
         checkNonZeros( herm, 1UL, 3UL );
         checkNonZeros( herm, 2UL, 2UL );

         if( herm(0,0) != cplx( 0, 0) || herm(0,1) != cplx(-2,-2) || herm(0,2) != cplx(-8,4) ||
             herm(1,0) != cplx(-2, 2) || herm(1,1) != cplx( 1, 0) || herm(1,2) != cplx( 5,1) ||
             herm(2,0) != cplx(-8,-4) || herm(2,1) != cplx( 5,-1) || herm(2,2) != cplx( 0,0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Function call operator failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( ( 0, 0) (-2,-2) (-8,4) )\n"
                                        "( (-2, 2) ( 1, 0) ( 5,1) )\n"
                                        "( (-8,-4) ( 5,-1) ( 0,0) )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Failure cases
      {
         OHT herm( 3UL );

         // Trying to write the diagonal element (0,0)
         try {
            herm(0,0) = cplx(5,5);

            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment to diagonal matrix element succeeded\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n";
            throw std::runtime_error( oss.str() );
         }
         catch( std::invalid_argument& ) {}

         // Trying to add to the diagonal element (1,1)
         try {
            herm(1,1) += cplx(5,5);

            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Addition assignment to diagonal matrix element succeeded\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n";
            throw std::runtime_error( oss.str() );
         }
         catch( std::invalid_argument& ) {}

         // Trying to subtract from the diagonal element (2,2)
         try {
            herm(2,2) -= cplx(5,5);

            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Subtraction assignment to diagonal matrix element succeeded\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n";
            throw std::runtime_error( oss.str() );
         }
         catch( std::invalid_argument& ) {}

         // Trying to multiply the diagonal element (1,1)
         try {
            herm(1,1) *= cplx(5,5);

            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Multiplication assignment to diagonal matrix element succeeded\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n";
            throw std::runtime_error( oss.str() );
         }
         catch( std::invalid_argument& ) {}

         // Trying to divide the diagonal element (1,1)
         try {
            herm(1,1) /= cplx(5,5);

            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Division assignment to diagonal matrix element succeeded\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n";
            throw std::runtime_error( oss.str() );
         }
         catch( std::invalid_argument& ) {}
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the HermitianMatrix iterator implementation.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the iterator implementation of the HermitianMatrix
// specialization. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void DenseComplexTest::testIterator()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      typedef HT::Iterator       Iterator;
      typedef HT::ConstIterator  ConstIterator;

      HT herm( 3UL );
      herm(0,0) = cplx( 4, 0);
      herm(0,1) = cplx( 1,-2);
      herm(1,2) = cplx(-2, 0);
      herm(2,2) = cplx( 3, 0);

      // Testing conversion from Iterator to ConstIterator
      {
         test_ = "Row-major Iterator/ConstIterator conversion";

         ConstIterator it( begin( herm, 1UL ) );

         if( it == end( herm, 1UL ) || *it != cplx(1,2) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Failed iterator conversion detected\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Counting the number of elements in 0th row via Iterator
      {
         test_ = "Row-major Iterator subtraction";

         const size_t number( end( herm, 0UL ) - begin( herm, 0UL ) );

         if( number != 3UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid number of elements detected\n"
                << " Details:\n"
                << "   Number of elements         : " << number << "\n"
                << "   Expected number of elements: 3\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Counting the number of elements in 1st row via ConstIterator
      {
         test_ = "Row-major ConstIterator subtraction";

         const size_t number( cend( herm, 1UL ) - cbegin( herm, 1UL ) );

         if( number != 3UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid number of elements detected\n"
                << " Details:\n"
                << "   Number of elements         : " << number << "\n"
                << "   Expected number of elements: 3\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing read-only access via ConstIterator
      {
         test_ = "Row-major read-only access via ConstIterator";

         ConstIterator it ( cbegin( herm, 2UL ) );
         ConstIterator end( cend( herm, 2UL ) );

         if( it == end || *it != cplx(0,0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid initial iterator detected\n";
            throw std::runtime_error( oss.str() );
         }

         ++it;

         if( it == end || *it != cplx(-2,0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator pre-increment failed\n";
            throw std::runtime_error( oss.str() );
         }

         --it;

         if( it == end || *it != cplx(0,0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator pre-decrement failed\n";
            throw std::runtime_error( oss.str() );
         }

         it++;

         if( it == end || *it != cplx(-2,0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator post-increment failed\n";
            throw std::runtime_error( oss.str() );
         }

         it--;

         if( it == end || *it != cplx(0,0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator post-decrement failed\n";
            throw std::runtime_error( oss.str() );
         }

         it += 2UL;

         if( it == end || *it != cplx(3,0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator addition assignment failed\n";
            throw std::runtime_error( oss.str() );
         }

         it -= 2UL;

         if( it == end || *it != cplx(0,0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator subtraction assignment failed\n";
            throw std::runtime_error( oss.str() );
         }

         it = it + 2UL;

         if( it == end || *it != cplx(3,0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator/scalar addition failed\n";
            throw std::runtime_error( oss.str() );
         }

         it = it - 2UL;

         if( it == end || *it != cplx(0,0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator/scalar subtraction failed\n";
            throw std::runtime_error( oss.str() );
         }

         it = 3UL + it;

         if( it != end ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Scalar/iterator addition failed\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing assignment via Iterator
      {
         test_ = "Row-major assignment via Iterator";

         Iterator it=begin( herm, 2UL );
         *it = cplx(1,2);
         ++it;
         *it = cplx(2,-3);
         ++it;
         *it = cplx(-3,0);

         if( herm(0,0) != cplx(4,0) || herm(0,1) != cplx(1,-2) || herm(0,2) != cplx( 1,-2) ||
             herm(1,0) != cplx(1,2) || herm(1,1) != cplx(0, 0) || herm(1,2) != cplx( 2, 3) ||
             herm(2,0) != cplx(1,2) || herm(2,1) != cplx(2,-3) || herm(2,2) != cplx(-3, 0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( (4,0) (1,-2) ( 1,-2) )\n"
                                        "( (1,2) (0, 0) ( 2, 3) )\n"
                                        "( (1,2) (2,-3) (-3, 0) )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing assignment to diagonal element via Iterator
      {
         test_ = "Row-major assignment to diagonal element via Iterator";

         try {
            const Iterator it = begin( herm, 0UL );
            *it = cplx(5,5);

            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment to diagonal matrix element succeeded\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n";
            throw std::runtime_error( oss.str() );
         }
         catch( std::invalid_argument& ) {}
      }

      // Testing addition assignment via Iterator
      {
         test_ = "Row-major addition assignment via Iterator";

         Iterator it=begin( herm, 2UL );
         *it += cplx(1,2);
         ++it;
         *it += cplx(2,-3);
         ++it;
         *it += cplx(-3,0);

         if( herm(0,0) != cplx(4,0) || herm(0,1) != cplx(1,-2) || herm(0,2) != cplx( 2,-4) ||
             herm(1,0) != cplx(1,2) || herm(1,1) != cplx(0, 0) || herm(1,2) != cplx( 4, 6) ||
             herm(2,0) != cplx(2,4) || herm(2,1) != cplx(4,-6) || herm(2,2) != cplx(-6, 0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( (4,0) (1,-2) ( 2,-4) )\n"
                                        "( (1,2) (0, 0) ( 4, 6) )\n"
                                        "( (2,4) (4,-6) (-6, 0) )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing addition assignment to diagonal element via Iterator
      {
         test_ = "Row-major addition assignment to diagonal element via Iterator";

         try {
            const Iterator it = begin( herm, 0UL );
            *it += cplx(5,5);

            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment to diagonal matrix element succeeded\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n";
            throw std::runtime_error( oss.str() );
         }
         catch( std::invalid_argument& ) {}
      }

      // Testing subtraction assignment via Iterator
      {
         test_ = "Row-major subtraction assignment via Iterator";

         Iterator it=begin( herm, 2UL );
         *it -= cplx(1,2);
         ++it;
         *it -= cplx(2,-3);
         ++it;
         *it -= cplx(-3,0);

         if( herm(0,0) != cplx(4,0) || herm(0,1) != cplx(1,-2) || herm(0,2) != cplx( 1,-2) ||
             herm(1,0) != cplx(1,2) || herm(1,1) != cplx(0, 0) || herm(1,2) != cplx( 2, 3) ||
             herm(2,0) != cplx(1,2) || herm(2,1) != cplx(2,-3) || herm(2,2) != cplx(-3, 0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( (4,0) (1,-2) (1,-2) )\n"
                                        "( (1,2) (0, 0) (2, 3) )\n"
                                        "( (1,2) (2,-3) (3, 0) )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing subtraction assignment to diagonal element via Iterator
      {
         test_ = "Row-major subtraction assignment to diagonal element via Iterator";

         try {
            const Iterator it = begin( herm, 0UL );
            *it -= cplx(5,5);

            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment to diagonal matrix element succeeded\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n";
            throw std::runtime_error( oss.str() );
         }
         catch( std::invalid_argument& ) {}
      }

      // Testing multiplication assignment via Iterator
      {
         test_ = "Row-major multiplication assignment via Iterator";

         Iterator it=begin( herm, 2UL );
         *it *= 2;
         ++it;
         *it *= 2;
         ++it;
         *it *= 2;

         if( herm(0,0) != cplx(4,0) || herm(0,1) != cplx(1,-2) || herm(0,2) != cplx( 2,-4) ||
             herm(1,0) != cplx(1,2) || herm(1,1) != cplx(0, 0) || herm(1,2) != cplx( 4, 6) ||
             herm(2,0) != cplx(2,4) || herm(2,1) != cplx(4,-6) || herm(2,2) != cplx(-6, 0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( (4,0) (1,-2) ( 2,-4) )\n"
                                        "( (1,2) (0, 0) ( 4, 6) )\n"
                                        "( (2,4) (4,-6) (-6, 0) )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing multiplication assignment to diagonal element via Iterator
      {
         test_ = "Row-major multiplication assignment to diagonal element via Iterator";

         try {
            const Iterator it = begin( herm, 0UL );
            *it *= cplx(5,5);

            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment to diagonal matrix element succeeded\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n";
            throw std::runtime_error( oss.str() );
         }
         catch( std::invalid_argument& ) {}
      }

      // Testing division assignment via Iterator
      {
         test_ = "Row-major division assignment via Iterator";

         Iterator it=begin( herm, 2UL );
         *it /= 2;
         ++it;
         *it /= 2;
         ++it;
         *it /= 2;

         if( herm(0,0) != cplx(4,0) || herm(0,1) != cplx(1,-2) || herm(0,2) != cplx( 1,-2) ||
             herm(1,0) != cplx(1,2) || herm(1,1) != cplx(0, 0) || herm(1,2) != cplx( 2, 3) ||
             herm(2,0) != cplx(1,2) || herm(2,1) != cplx(2,-3) || herm(2,2) != cplx(-3, 0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( (4,0) (1,-2) ( 1,-2) )\n"
                                        "( (1,2) (0, 0) ( 2, 3) )\n"
                                        "( (1,2) (2,-3) (-3, 0) )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing division assignment to diagonal element via Iterator
      {
         test_ = "Row-major division assignment to diagonal element via Iterator";

         try {
            const Iterator it = begin( herm, 0UL );
            *it /= cplx(5,5);

            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment to diagonal matrix element succeeded\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n";
            throw std::runtime_error( oss.str() );
         }
         catch( std::invalid_argument& ) {}
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      typedef OHT::Iterator       Iterator;
      typedef OHT::ConstIterator  ConstIterator;

      OHT herm( 3UL );
      herm(0,0) = cplx( 4, 0);
      herm(0,1) = cplx( 1,-2);
      herm(1,2) = cplx(-2, 0);
      herm(2,2) = cplx( 3, 0);

      // Testing conversion from Iterator to ConstIterator
      {
         test_ = "Column-major Iterator/ConstIterator conversion";

         ConstIterator it( begin( herm, 1UL ) );

         if( it == end( herm, 1UL ) || *it != cplx(1,-2) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Failed iterator conversion detected\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Counting the number of elements in 0th row via Iterator
      {
         test_ = "Column-major Iterator subtraction";

         const size_t number( end( herm, 0UL ) - begin( herm, 0UL ) );

         if( number != 3UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid number of elements detected\n"
                << " Details:\n"
                << "   Number of elements         : " << number << "\n"
                << "   Expected number of elements: 3\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Counting the number of elements in 1st row via ConstIterator
      {
         test_ = "Column-major ConstIterator subtraction";

         const size_t number( cend( herm, 1UL ) - cbegin( herm, 1UL ) );

         if( number != 3UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid number of elements detected\n"
                << " Details:\n"
                << "   Number of elements         : " << number << "\n"
                << "   Expected number of elements: 3\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing read-only access via ConstIterator
      {
         test_ = "Column-major read-only access via ConstIterator";

         ConstIterator it ( cbegin( herm, 2UL ) );
         ConstIterator end( cend( herm, 2UL ) );

         if( it == end || *it != cplx(0,0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid initial iterator detected\n";
            throw std::runtime_error( oss.str() );
         }

         ++it;

         if( it == end || *it != cplx(-2,0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator pre-increment failed\n";
            throw std::runtime_error( oss.str() );
         }

         --it;

         if( it == end || *it != cplx(0,0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator pre-decrement failed\n";
            throw std::runtime_error( oss.str() );
         }

         it++;

         if( it == end || *it != cplx(-2,0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator post-increment failed\n";
            throw std::runtime_error( oss.str() );
         }

         it--;

         if( it == end || *it != cplx(0,0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator post-decrement failed\n";
            throw std::runtime_error( oss.str() );
         }

         it += 2UL;

         if( it == end || *it != cplx(3,0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator addition assignment failed\n";
            throw std::runtime_error( oss.str() );
         }

         it -= 2UL;

         if( it == end || *it != cplx(0,0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator subtraction assignment failed\n";
            throw std::runtime_error( oss.str() );
         }

         it = it + 2UL;

         if( it == end || *it != cplx(3,0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator/scalar addition failed\n";
            throw std::runtime_error( oss.str() );
         }

         it = it - 2UL;

         if( it == end || *it != cplx(0,0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator/scalar subtraction failed\n";
            throw std::runtime_error( oss.str() );
         }

         it = 3UL + it;

         if( it != end ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Scalar/iterator addition failed\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing assignment via Iterator
      {
         test_ = "Column-major assignment via Iterator";

         Iterator it=begin( herm, 2UL );
         *it = cplx(1,-2);
         ++it;
         *it = cplx(2,3);
         ++it;
         *it = cplx(-3,0);

         if( herm(0,0) != cplx(4,0) || herm(0,1) != cplx(1,-2) || herm(0,2) != cplx( 1,-2) ||
             herm(1,0) != cplx(1,2) || herm(1,1) != cplx(0, 0) || herm(1,2) != cplx( 2, 3) ||
             herm(2,0) != cplx(1,2) || herm(2,1) != cplx(2,-3) || herm(2,2) != cplx(-3, 0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( (4,0) (1,-2) ( 1,-2) )\n"
                                        "( (1,2) (0, 0) ( 2, 3) )\n"
                                        "( (1,2) (2,-3) (-3, 0) )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing assignment to diagonal element via Iterator
      {
         test_ = "Column-major assignment to diagonal element via Iterator";

         try {
            const Iterator it = begin( herm, 0UL );
            *it = cplx(5,5);

            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment to diagonal matrix element succeeded\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n";
            throw std::runtime_error( oss.str() );
         }
         catch( std::invalid_argument& ) {}
      }

      // Testing addition assignment via Iterator
      {
         test_ = "Column-major addition assignment via Iterator";

         Iterator it=begin( herm, 2UL );
         *it += cplx(1,-2);
         ++it;
         *it += cplx(2,3);
         ++it;
         *it += cplx(-3,0);

         if( herm(0,0) != cplx(4,0) || herm(0,1) != cplx(1,-2) || herm(0,2) != cplx( 2,-4) ||
             herm(1,0) != cplx(1,2) || herm(1,1) != cplx(0, 0) || herm(1,2) != cplx( 4, 6) ||
             herm(2,0) != cplx(2,4) || herm(2,1) != cplx(4,-6) || herm(2,2) != cplx(-6, 0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( (4,0) (1,-2) ( 2,-4) )\n"
                                        "( (1,2) (0, 0) ( 4, 6) )\n"
                                        "( (2,4) (4,-6) (-6, 0) )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing addition assignment to diagonal element via Iterator
      {
         test_ = "Column-major addition assignment to diagonal element via Iterator";

         try {
            const Iterator it = begin( herm, 0UL );
            *it += cplx(5,5);

            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment to diagonal matrix element succeeded\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n";
            throw std::runtime_error( oss.str() );
         }
         catch( std::invalid_argument& ) {}
      }

      // Testing subtraction assignment via Iterator
      {
         test_ = "Column-major subtraction assignment via Iterator";

         Iterator it=begin( herm, 2UL );
         *it -= cplx(1,-2);
         ++it;
         *it -= cplx(2,3);
         ++it;
         *it -= cplx(-3,0);

         if( herm(0,0) != cplx(4,0) || herm(0,1) != cplx(1,-2) || herm(0,2) != cplx( 1,-2) ||
             herm(1,0) != cplx(1,2) || herm(1,1) != cplx(0, 0) || herm(1,2) != cplx( 2, 3) ||
             herm(2,0) != cplx(1,2) || herm(2,1) != cplx(2,-3) || herm(2,2) != cplx(-3, 0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( (4,0) (1,-2) ( 1,-2) )\n"
                                        "( (1,2) (0, 0) ( 2, 3) )\n"
                                        "( (1,2) (2,-3) (-3, 0) )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing subtraction assignment to diagonal element via Iterator
      {
         test_ = "Column-major subtraction assignment to diagonal element via Iterator";

         try {
            const Iterator it = begin( herm, 0UL );
            *it -= cplx(5,5);

            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment to diagonal matrix element succeeded\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n";
            throw std::runtime_error( oss.str() );
         }
         catch( std::invalid_argument& ) {}
      }

      // Testing multiplication assignment via Iterator
      {
         test_ = "Column-major multiplication assignment via Iterator";

         Iterator it=begin( herm, 2UL );
         *it *= 2;
         ++it;
         *it *= 2;
         ++it;
         *it *= 2;

         if( herm(0,0) != cplx(4,0) || herm(0,1) != cplx(1,-2) || herm(0,2) != cplx( 2,-4) ||
             herm(1,0) != cplx(1,2) || herm(1,1) != cplx(0, 0) || herm(1,2) != cplx( 4, 6) ||
             herm(2,0) != cplx(2,4) || herm(2,1) != cplx(4,-6) || herm(2,2) != cplx(-6, 0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( (4,0) (1,-2) ( 2,-4) )\n"
                                        "( (1,2) (0, 0) ( 4, 6) )\n"
                                        "( (2,4) (4,-6) (-6, 0) )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing multiplication assignment to diagonal element via Iterator
      {
         test_ = "Column-major multiplication assignment to diagonal element via Iterator";

         try {
            const Iterator it = begin( herm, 0UL );
            *it *= cplx(5,5);

            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment to diagonal matrix element succeeded\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n";
            throw std::runtime_error( oss.str() );
         }
         catch( std::invalid_argument& ) {}
      }

      // Testing division assignment via Iterator
      {
         test_ = "Column-major division assignment via Iterator";

         Iterator it=begin( herm, 2UL );
         *it /= 2;
         ++it;
         *it /= 2;
         ++it;
         *it /= 2;

         if( herm(0,0) != cplx(4,0) || herm(0,1) != cplx(1,-2) || herm(0,2) != cplx( 1,-2) ||
             herm(1,0) != cplx(1,2) || herm(1,1) != cplx(0, 0) || herm(1,2) != cplx( 2, 3) ||
             herm(2,0) != cplx(1,2) || herm(2,1) != cplx(2,-3) || herm(2,2) != cplx(-3, 0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( (4,0) (1,-2) ( 1,-2) )\n"
                                        "( (1,2) (0, 0) ( 2, 3) )\n"
                                        "( (1,2) (2,-3) (-3, 0) )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing division assignment to diagonal element via Iterator
      {
         test_ = "Column-major division assignment to diagonal element via Iterator";

         try {
            const Iterator it = begin( herm, 0UL );
            *it /= cplx(5,5);

            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment to diagonal matrix element succeeded\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n";
            throw std::runtime_error( oss.str() );
         }
         catch( std::invalid_argument& ) {}
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c nonZeros() member function of the HermitianMatrix specialization.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c nonZeros() member function of the HermitianMatrix
// specialization. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void DenseComplexTest::testNonZeros()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major HermitianMatrix::nonZeros()";

      // Empty matrix
      {
         HT herm( 3UL );

         checkRows    ( herm, 3UL );
         checkColumns ( herm, 3UL );
         checkCapacity( herm, 9UL );
         checkNonZeros( herm, 0UL );
         checkNonZeros( herm, 0UL, 0UL );
         checkNonZeros( herm, 1UL, 0UL );
         checkNonZeros( herm, 2UL, 0UL );

         if( herm(0,0) != cplx(0,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(0,0) ||
             herm(1,0) != cplx(0,0) || herm(1,1) != cplx(0,0) || herm(1,2) != cplx(0,0) ||
             herm(2,0) != cplx(0,0) || herm(2,1) != cplx(0,0) || herm(2,2) != cplx(0,0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Initialization failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( (0,0) (0,0) (0,0) )\n"
                                        "( (0,0) (0,0) (0,0) )\n"
                                        "( (0,0) (0,0) (0,0) )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Partially filled matrix
      {
         HT herm( 3UL );
         herm(0,0) = cplx( 1, 0);
         herm(1,2) = cplx(-2,-3);
         herm(2,0) = cplx( 0, 0);
         herm(2,2) = cplx( 3, 0);

         checkRows    ( herm, 3UL );
         checkColumns ( herm, 3UL );
         checkCapacity( herm, 9UL );
         checkNonZeros( herm, 4UL );
         checkNonZeros( herm, 0UL, 1UL );
         checkNonZeros( herm, 1UL, 1UL );
         checkNonZeros( herm, 2UL, 2UL );

         if( herm(0,0) != cplx(1,0) || herm(0,1) != cplx( 0,0) || herm(0,2) != cplx( 0, 0) ||
             herm(1,0) != cplx(0,0) || herm(1,1) != cplx( 0,0) || herm(1,2) != cplx(-2,-3) ||
             herm(2,0) != cplx(0,0) || herm(2,1) != cplx(-2,3) || herm(2,2) != cplx( 3, 0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Initialization failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( (1,0) ( 0,0) ( 0, 0) )\n"
                                        "( (0,0) ( 0,0) (-2,-3) )\n"
                                        "( (0,0) (-2,3) ( 3, 0) )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Fully filled matrix
      {
         HT herm( 3UL );
         herm(0,0) = cplx(-1, 0);
         herm(0,1) = cplx( 2, 1);
         herm(0,2) = cplx(-3,-2);
         herm(1,1) = cplx( 4, 0);
         herm(1,2) = cplx(-5,-1);
         herm(2,2) = cplx( 6, 0);

         checkRows    ( herm, 3UL );
         checkColumns ( herm, 3UL );
         checkCapacity( herm, 9UL );
         checkNonZeros( herm, 9UL );
         checkNonZeros( herm, 0UL, 3UL );
         checkNonZeros( herm, 1UL, 3UL );
         checkNonZeros( herm, 2UL, 3UL );

         if( herm(0,0) != cplx(-1, 0) || herm(0,1) != cplx( 2,1) || herm(0,2) != cplx(-3,-2) ||
             herm(1,0) != cplx( 2,-1) || herm(1,1) != cplx( 4,0) || herm(1,2) != cplx(-5,-1) ||
             herm(2,0) != cplx(-3, 2) || herm(2,1) != cplx(-5,1) || herm(2,2) != cplx( 6, 0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Initialization failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( (-1, 0) ( 2,1) (-3,-2) )\n"
                                        "( ( 2,-1) ( 4,0) (-5,-1) )\n"
                                        "( (-3, 2) (-5,1) ( 6, 0) )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major HermitianMatrix::nonZeros()";

      // Empty matrix
      {
         OHT herm( 3UL );

         checkRows    ( herm, 3UL );
         checkColumns ( herm, 3UL );
         checkCapacity( herm, 9UL );
         checkNonZeros( herm, 0UL );
         checkNonZeros( herm, 0UL, 0UL );
         checkNonZeros( herm, 1UL, 0UL );
         checkNonZeros( herm, 2UL, 0UL );

         if( herm(0,0) != cplx(0,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(0,0) ||
             herm(1,0) != cplx(0,0) || herm(1,1) != cplx(0,0) || herm(1,2) != cplx(0,0) ||
             herm(2,0) != cplx(0,0) || herm(2,1) != cplx(0,0) || herm(2,2) != cplx(0,0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Initialization failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( (0,0) (0,0) (0,0) )\n"
                                        "( (0,0) (0,0) (0,0) )\n"
                                        "( (0,0) (0,0) (0,0) )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Partially filled matrix
      {
         HT herm( 3UL );
         herm(0,0) = cplx( 1, 0);
         herm(1,2) = cplx(-2,-3);
         herm(2,0) = cplx( 0, 0);
         herm(2,2) = cplx( 3, 0);

         checkRows    ( herm, 3UL );
         checkColumns ( herm, 3UL );
         checkCapacity( herm, 9UL );
         checkNonZeros( herm, 4UL );
         checkNonZeros( herm, 0UL, 1UL );
         checkNonZeros( herm, 1UL, 1UL );
         checkNonZeros( herm, 2UL, 2UL );

         if( herm(0,0) != cplx(1,0) || herm(0,1) != cplx( 0,0) || herm(0,2) != cplx( 0, 0) ||
             herm(1,0) != cplx(0,0) || herm(1,1) != cplx( 0,0) || herm(1,2) != cplx(-2,-3) ||
             herm(2,0) != cplx(0,0) || herm(2,1) != cplx(-2,3) || herm(2,2) != cplx( 3, 0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Initialization failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( (1,0) ( 0,0) ( 0, 0) )\n"
                                        "( (0,0) ( 0,0) (-2,-3) )\n"
                                        "( (0,0) (-2,3) ( 3, 0) )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Fully filled matrix
      {
         HT herm( 3UL );
         herm(0,0) = cplx(-1, 0);
         herm(0,1) = cplx( 2, 1);
         herm(0,2) = cplx(-3,-2);
         herm(1,1) = cplx( 4, 0);
         herm(1,2) = cplx(-5,-1);
         herm(2,2) = cplx( 6, 0);

         checkRows    ( herm, 3UL );
         checkColumns ( herm, 3UL );
         checkCapacity( herm, 9UL );
         checkNonZeros( herm, 9UL );
         checkNonZeros( herm, 0UL, 3UL );
         checkNonZeros( herm, 1UL, 3UL );
         checkNonZeros( herm, 2UL, 3UL );

         if( herm(0,0) != cplx(-1, 0) || herm(0,1) != cplx( 2,1) || herm(0,2) != cplx(-3,-2) ||
             herm(1,0) != cplx( 2,-1) || herm(1,1) != cplx( 4,0) || herm(1,2) != cplx(-5,-1) ||
             herm(2,0) != cplx(-3, 2) || herm(2,1) != cplx(-5,1) || herm(2,2) != cplx( 6, 0) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Initialization failed\n"
                << " Details:\n"
                << "   Result:\n" << herm << "\n"
                << "   Expected result:\n( (-1, 0) ( 2,1) (-3,-2) )\n"
                                        "( ( 2,-1) ( 4,0) (-5,-1) )\n"
                                        "( (-3, 2) (-5,1) ( 6, 0) )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c reset() member function of the HermitianMatrix specialization.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c reset() member function of the HermitianMatrix
// specialization. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void DenseComplexTest::testReset()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major HermitianMatrix::reset()";

      // Initialization check
      HT herm( 3UL );
      herm(0,0) = cplx(-1, 0);
      herm(0,1) = cplx( 2, 1);
      herm(0,2) = cplx(-3,-2);
      herm(1,1) = cplx( 4, 0);
      herm(1,2) = cplx(-5,-1);
      herm(2,2) = cplx( 6, 0);

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 9UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 3UL );
      checkNonZeros( herm, 2UL, 3UL );

      if( herm(0,0) != cplx(-1, 0) || herm(0,1) != cplx( 2, 1) || herm(0,2) != cplx(-3,-2) ||
          herm(1,0) != cplx( 2,-1) || herm(1,1) != cplx( 4, 0) || herm(1,2) != cplx(-5,-1) ||
          herm(2,0) != cplx(-3, 2) || herm(2,1) != cplx(-5, 1) || herm(2,2) != cplx( 6, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Initialization failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (-1, 0) ( 2,1) (-3,-2) )\n"
                                     "( ( 2,-1) ( 4,0) (-5,-1) )\n"
                                     "( (-3, 2) (-5,1) ( 6, 0) )\n";
         throw std::runtime_error( oss.str() );
      }

      // Resetting a single element
      reset( herm(0,1) );

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 2UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 3UL );

      if( herm(0,0) != cplx(-1,0) || herm(0,1) != cplx( 0,0) || herm(0,2) != cplx(-3,-2) ||
          herm(1,0) != cplx( 0,0) || herm(1,1) != cplx( 4,0) || herm(1,2) != cplx(-5,-1) ||
          herm(2,0) != cplx(-3,2) || herm(2,1) != cplx(-5,1) || herm(2,2) != cplx( 6, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Reset operation failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (-1,0) ( 0,0) (-3,-2) )\n"
                                     "( ( 0,0) ( 4,0) (-5,-1) )\n"
                                     "( (-3,2) (-5,1) ( 6, 0) )\n";
         throw std::runtime_error( oss.str() );
      }

      // Resetting row 1
      reset( herm, 1UL );

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 4UL );
      checkNonZeros( herm, 0UL, 2UL );
      checkNonZeros( herm, 1UL, 0UL );
      checkNonZeros( herm, 2UL, 2UL );

      if( herm(0,0) != cplx(-1,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(-3,-2) ||
          herm(1,0) != cplx( 0,0) || herm(1,1) != cplx(0,0) || herm(1,2) != cplx( 0, 0) ||
          herm(2,0) != cplx(-3,2) || herm(2,1) != cplx(0,0) || herm(2,2) != cplx( 6, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Reset operation failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (-1,0) (0,0) (-3,-2) )\n"
                                     "( ( 0,0) (0,0) ( 0, 0) )\n"
                                     "( (-3,2) (0,0) ( 6, 0) )\n";
         throw std::runtime_error( oss.str() );
      }

      // Resetting the entire matrix
      reset( herm );

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 0UL );
      checkNonZeros( herm, 0UL, 0UL );
      checkNonZeros( herm, 1UL, 0UL );
      checkNonZeros( herm, 2UL, 0UL );

      if( herm(0,0) != cplx(0,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(0,0) ||
          herm(1,0) != cplx(0,0) || herm(1,1) != cplx(0,0) || herm(1,2) != cplx(0,0) ||
          herm(2,0) != cplx(0,0) || herm(2,1) != cplx(0,0) || herm(2,2) != cplx(0,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Reset operation failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (0,0) (0,0) (0,0) )\n"
                                     "( (0,0) (0,0) (0,0) )\n"
                                     "( (0,0) (0,0) (0,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major HermitianMatrix::reset()";

      // Initialization check
      OHT herm( 3UL );
      herm(0,0) = cplx(-1, 0);
      herm(0,1) = cplx( 2, 1);
      herm(0,2) = cplx(-3,-2);
      herm(1,1) = cplx( 4, 0);
      herm(1,2) = cplx(-5,-1);
      herm(2,2) = cplx( 6, 0);

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 9UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 3UL );
      checkNonZeros( herm, 2UL, 3UL );

      if( herm(0,0) != cplx(-1, 0) || herm(0,1) != cplx( 2, 1) || herm(0,2) != cplx(-3,-2) ||
          herm(1,0) != cplx( 2,-1) || herm(1,1) != cplx( 4, 0) || herm(1,2) != cplx(-5,-1) ||
          herm(2,0) != cplx(-3, 2) || herm(2,1) != cplx(-5, 1) || herm(2,2) != cplx( 6, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Initialization failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (-1, 0) ( 2,1) (-3,-2) )\n"
                                     "( ( 2,-1) ( 4,0) (-5,-1) )\n"
                                     "( (-3, 2) (-5,1) ( 6, 0) )\n";
         throw std::runtime_error( oss.str() );
      }

      // Resetting a single element
      reset( herm(0,1) );

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 2UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 3UL );

      if( herm(0,0) != cplx(-1,0) || herm(0,1) != cplx( 0,0) || herm(0,2) != cplx(-3,-2) ||
          herm(1,0) != cplx( 0,0) || herm(1,1) != cplx( 4,0) || herm(1,2) != cplx(-5,-1) ||
          herm(2,0) != cplx(-3,2) || herm(2,1) != cplx(-5,1) || herm(2,2) != cplx( 6, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Reset operation failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (-1,0) ( 0,0) (-3,-2) )\n"
                                     "( ( 0,0) ( 4,0) (-5,-1) )\n"
                                     "( (-3,2) (-5,1) ( 6, 0) )\n";
         throw std::runtime_error( oss.str() );
      }

      // Resetting row 1
      reset( herm, 1UL );

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 4UL );
      checkNonZeros( herm, 0UL, 2UL );
      checkNonZeros( herm, 1UL, 0UL );
      checkNonZeros( herm, 2UL, 2UL );

      if( herm(0,0) != cplx(-1,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(-3,-2) ||
          herm(1,0) != cplx( 0,0) || herm(1,1) != cplx(0,0) || herm(1,2) != cplx( 0, 0) ||
          herm(2,0) != cplx(-3,2) || herm(2,1) != cplx(0,0) || herm(2,2) != cplx( 6, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Reset operation failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (-1,0) (0,0) (-3,-2) )\n"
                                     "( ( 0,0) (0,0) ( 0, 0) )\n"
                                     "( (-3,2) (0,0) ( 6, 0) )\n";
         throw std::runtime_error( oss.str() );
      }

      // Resetting the entire matrix
      reset( herm );

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 0UL );
      checkNonZeros( herm, 0UL, 0UL );
      checkNonZeros( herm, 1UL, 0UL );
      checkNonZeros( herm, 2UL, 0UL );

      if( herm(0,0) != cplx(0,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(0,0) ||
          herm(1,0) != cplx(0,0) || herm(1,1) != cplx(0,0) || herm(1,2) != cplx(0,0) ||
          herm(2,0) != cplx(0,0) || herm(2,1) != cplx(0,0) || herm(2,2) != cplx(0,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Reset operation failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (0,0) (0,0) (0,0) )\n"
                                     "( (0,0) (0,0) (0,0) )\n"
                                     "( (0,0) (0,0) (0,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c clear() member function of the HermitianMatrix specialization.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c clear() member function of the HermitianMatrix
// specialization. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void DenseComplexTest::testClear()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major HermitianMatrix::clear()";

      // Initialization check
      HT herm( 3UL );
      herm(0,0) = cplx(-1, 0);
      herm(0,1) = cplx( 2, 1);
      herm(0,2) = cplx(-3,-2);
      herm(1,1) = cplx( 4, 0);
      herm(1,2) = cplx(-5,-1);
      herm(2,2) = cplx( 6, 0);

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 9UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 3UL );
      checkNonZeros( herm, 2UL, 3UL );

      if( herm(0,0) != cplx(-1, 0) || herm(0,1) != cplx( 2, 1) || herm(0,2) != cplx(-3,-2) ||
          herm(1,0) != cplx( 2,-1) || herm(1,1) != cplx( 4, 0) || herm(1,2) != cplx(-5,-1) ||
          herm(2,0) != cplx(-3, 2) || herm(2,1) != cplx(-5, 1) || herm(2,2) != cplx( 6, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Initialization failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (-1, 0) ( 2,1) (-3,-2) )\n"
                                     "( ( 2,-1) ( 4,0) (-5,-1) )\n"
                                     "( (-3, 2) (-5,1) ( 6, 0) )\n";
         throw std::runtime_error( oss.str() );
      }

      // Clearing a single element
      clear( herm(0,1) );

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 2UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 3UL );

      if( herm(0,0) != cplx(-1,0) || herm(0,1) != cplx( 0,0) || herm(0,2) != cplx(-3,-2) ||
          herm(1,0) != cplx( 0,0) || herm(1,1) != cplx( 4,0) || herm(1,2) != cplx(-5,-1) ||
          herm(2,0) != cplx(-3,2) || herm(2,1) != cplx(-5,1) || herm(2,2) != cplx( 6, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Clear operation failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (-1,0) ( 0,0) (-3,-2) )\n"
                                     "( ( 0,0) ( 4,0) (-5,-1) )\n"
                                     "( (-3,2) (-5,1) ( 6, 0) )\n";
         throw std::runtime_error( oss.str() );
      }

      // Clearing the matrix
      clear( herm );

      checkRows    ( herm, 0UL );
      checkColumns ( herm, 0UL );
      checkNonZeros( herm, 0UL );
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major HermitianMatrix::clear()";

      // Initialization check
      OHT herm( 3UL );
      herm(0,0) = cplx(-1, 0);
      herm(0,1) = cplx( 2, 1);
      herm(0,2) = cplx(-3,-2);
      herm(1,1) = cplx( 4, 0);
      herm(1,2) = cplx(-5,-1);
      herm(2,2) = cplx( 6, 0);

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 9UL );
      checkNonZeros( herm, 0UL, 3UL );
      checkNonZeros( herm, 1UL, 3UL );
      checkNonZeros( herm, 2UL, 3UL );

      if( herm(0,0) != cplx(-1, 0) || herm(0,1) != cplx( 2, 1) || herm(0,2) != cplx(-3,-2) ||
          herm(1,0) != cplx( 2,-1) || herm(1,1) != cplx( 4, 0) || herm(1,2) != cplx(-5,-1) ||
          herm(2,0) != cplx(-3, 2) || herm(2,1) != cplx(-5, 1) || herm(2,2) != cplx( 6, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Initialization failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (-1, 0) ( 2,1) (-3,-2) )\n"
                                     "( ( 2,-1) ( 4,0) (-5,-1) )\n"
                                     "( (-3, 2) (-5,1) ( 6, 0) )\n";
         throw std::runtime_error( oss.str() );
      }

      // Clearing a single element
      clear( herm(0,1) );

      checkRows    ( herm, 3UL );
      checkColumns ( herm, 3UL );
      checkCapacity( herm, 9UL );
      checkNonZeros( herm, 7UL );
      checkNonZeros( herm, 0UL, 2UL );
      checkNonZeros( herm, 1UL, 2UL );
      checkNonZeros( herm, 2UL, 3UL );

      if( herm(0,0) != cplx(-1,0) || herm(0,1) != cplx( 0,0) || herm(0,2) != cplx(-3,-2) ||
          herm(1,0) != cplx( 0,0) || herm(1,1) != cplx( 4,0) || herm(1,2) != cplx(-5,-1) ||
          herm(2,0) != cplx(-3,2) || herm(2,1) != cplx(-5,1) || herm(2,2) != cplx( 6, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Clear operation failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (-1,0) ( 0,0) (-3,-2) )\n"
                                     "( ( 0,0) ( 4,0) (-5,-1) )\n"
                                     "( (-3,2) (-5,1) ( 6, 0) )\n";
         throw std::runtime_error( oss.str() );
      }

      // Clearing the matrix
      clear( herm );

      checkRows    ( herm, 0UL );
      checkColumns ( herm, 0UL );
      checkNonZeros( herm, 0UL );
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c resize() member function of the HermitianMatrix specialization.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c resize() member function of the HermitianMatrix
// specialization. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void DenseComplexTest::testResize()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major HermitianMatrix::resize()";

      // Initialization check
      HT herm;

      checkRows    ( herm, 0UL );
      checkColumns ( herm, 0UL );
      checkNonZeros( herm, 0UL );

      // Resizing to 2x2
      herm.resize( 2UL );

      checkRows    ( herm, 2UL );
      checkColumns ( herm, 2UL );
      checkCapacity( herm, 4UL );
      checkNonZeros( herm, 0UL );
      checkNonZeros( herm, 0UL, 0UL );
      checkNonZeros( herm, 1UL, 0UL );

      if( herm(0,0) != cplx(0,0) || herm(0,1) != cplx(0,0) ||
          herm(1,0) != cplx(0,0) || herm(1,1) != cplx(0,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Resizing the matrix failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (0,0) (0,0) )\n"
                                     "( (0,0) (0,0) )\n";
         throw std::runtime_error( oss.str() );
      }

      // Resizing to 4x4 and preserving the elements
      herm(0,1) = cplx(1,-1);
      herm(1,1) = cplx(2, 0);
      herm.resize( 4UL, true );

      checkRows    ( herm,  4UL );
      checkColumns ( herm,  4UL );
      checkCapacity( herm, 16UL );
      checkNonZeros( herm,  3UL );
      checkNonZeros( herm,  0UL, 1UL );
      checkNonZeros( herm,  1UL, 2UL );
      checkNonZeros( herm,  2UL, 0UL );
      checkNonZeros( herm,  3UL, 0UL );

      if( herm(0,0) != cplx(0,0) || herm(0,1) != cplx(1,-1) || herm(0,2) != cplx(0,0) || herm(0,3) != cplx(0,0) ||
          herm(1,0) != cplx(1,1) || herm(1,1) != cplx(2, 0) || herm(1,2) != cplx(0,0) || herm(1,3) != cplx(0,0) ||
          herm(2,0) != cplx(0,0) || herm(2,1) != cplx(0, 0) || herm(2,2) != cplx(0,0) || herm(2,3) != cplx(0,0) ||
          herm(3,0) != cplx(0,0) || herm(3,1) != cplx(0, 0) || herm(3,2) != cplx(0,0) || herm(3,3) != cplx(0,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Resizing the matrix failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (0,0) (1,-1) (0,0) (0,0) )\n"
                                     "( (1,1) (2, 0) (0,0) (0,0) )\n"
                                     "( (0,0) (0, 0) (0,0) (0,0) )\n"
                                     "( (0,0) (0, 0) (0,0) (0,0) )\n";
         throw std::runtime_error( oss.str() );
      }

      // Resizing to 2x2
      herm(2,2) = cplx(3,0);
      herm.resize( 2UL );

      checkRows    ( herm, 2UL );
      checkColumns ( herm, 2UL );
      checkCapacity( herm, 4UL );
      checkNonZeros( herm, 3UL );
      checkNonZeros( herm, 0UL, 1UL );
      checkNonZeros( herm, 1UL, 2UL );

      if( herm(0,0) != cplx(0,0) || herm(0,1) != cplx(1,-1) ||
          herm(1,0) != cplx(1,1) || herm(1,1) != cplx(2,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Resizing the matrix failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (0,0) (1,-1) )\n"
                                     "( (1,1) (2,0) )\n";
         throw std::runtime_error( oss.str() );
      }

      // Resizing to 0x0
      herm.resize( 0UL );

      checkRows    ( herm, 0UL );
      checkColumns ( herm, 0UL );
      checkNonZeros( herm, 0UL );
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major HermitianMatrix::resize()";

      // Initialization check
      OHT herm;

      checkRows    ( herm, 0UL );
      checkColumns ( herm, 0UL );
      checkNonZeros( herm, 0UL );

      // Resizing to 2x2
      herm.resize( 2UL );

      checkRows    ( herm, 2UL );
      checkColumns ( herm, 2UL );
      checkCapacity( herm, 4UL );
      checkNonZeros( herm, 0UL );
      checkNonZeros( herm, 0UL, 0UL );
      checkNonZeros( herm, 1UL, 0UL );

      if( herm(0,0) != cplx(0,0) || herm(0,1) != cplx(0,0) ||
          herm(1,0) != cplx(0,0) || herm(1,1) != cplx(0,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Resizing the matrix failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (0,0) (0,0) )\n"
                                     "( (0,0) (0,0) )\n";
         throw std::runtime_error( oss.str() );
      }

      // Resizing to 4x4 and preserving the elements
      herm(0,1) = cplx(1,-1);
      herm(1,1) = cplx(2, 0);
      herm.resize( 4UL, true );

      checkRows    ( herm,  4UL );
      checkColumns ( herm,  4UL );
      checkCapacity( herm, 16UL );
      checkNonZeros( herm,  3UL );
      checkNonZeros( herm,  0UL, 1UL );
      checkNonZeros( herm,  1UL, 2UL );
      checkNonZeros( herm,  2UL, 0UL );
      checkNonZeros( herm,  3UL, 0UL );

      if( herm(0,0) != cplx(0,0) || herm(0,1) != cplx(1,-1) || herm(0,2) != cplx(0,0) || herm(0,3) != cplx(0,0) ||
          herm(1,0) != cplx(1,1) || herm(1,1) != cplx(2, 0) || herm(1,2) != cplx(0,0) || herm(1,3) != cplx(0,0) ||
          herm(2,0) != cplx(0,0) || herm(2,1) != cplx(0, 0) || herm(2,2) != cplx(0,0) || herm(2,3) != cplx(0,0) ||
          herm(3,0) != cplx(0,0) || herm(3,1) != cplx(0, 0) || herm(3,2) != cplx(0,0) || herm(3,3) != cplx(0,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Resizing the matrix failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (0,0) (1,-1) (0,0) (0,0) )\n"
                                     "( (1,1) (2, 0) (0,0) (0,0) )\n"
                                     "( (0,0) (0, 0) (0,0) (0,0) )\n"
                                     "( (0,0) (0, 0) (0,0) (0,0) )\n";
         throw std::runtime_error( oss.str() );
      }

      // Resizing to 2x2
      herm(2,2) = cplx(3,0);
      herm.resize( 2UL );

      checkRows    ( herm, 2UL );
      checkColumns ( herm, 2UL );
      checkCapacity( herm, 4UL );
      checkNonZeros( herm, 3UL );
      checkNonZeros( herm, 0UL, 1UL );
      checkNonZeros( herm, 1UL, 2UL );

      if( herm(0,0) != cplx(0,0) || herm(0,1) != cplx(1,-1) ||
          herm(1,0) != cplx(1,1) || herm(1,1) != cplx(2,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Resizing the matrix failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (0,0) (1,-1) )\n"
                                     "( (1,1) (2,0) )\n";
         throw std::runtime_error( oss.str() );
      }

      // Resizing to 0x0
      herm.resize( 0UL );

      checkRows    ( herm, 0UL );
      checkColumns ( herm, 0UL );
      checkNonZeros( herm, 0UL );
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c extend() member function of the HermitianMatrix specialization.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c extend() member function of the HermitianMatrix
// specialization. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void DenseComplexTest::testExtend()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major HermitianMatrix::extend()";

      // Initialization check
      HT herm;

      checkRows    ( herm, 0UL );
      checkColumns ( herm, 0UL );
      checkNonZeros( herm, 0UL );

      // Extending the size of the matrix to 2x2
      herm.extend( 2UL );

      checkRows    ( herm, 2UL );
      checkColumns ( herm, 2UL );
      checkCapacity( herm, 4UL );
      checkNonZeros( herm, 0UL );
      checkNonZeros( herm, 0UL, 0UL );
      checkNonZeros( herm, 1UL, 0UL );

      if( herm(0,0) != cplx(0,0) || herm(0,1) != cplx(0,0) ||
          herm(1,0) != cplx(0,0) || herm(1,1) != cplx(0,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Extending the matrix failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (0,0) (0,0) )\n"
                                     "( (0,0) (0,0) )\n";
         throw std::runtime_error( oss.str() );
      }

      // Extending to 4x4 and preserving the elements
      herm(0,1) = cplx(1,-1);
      herm(1,1) = cplx(2, 0);
      herm.extend( 2UL, true );

      checkRows    ( herm,  4UL );
      checkColumns ( herm,  4UL );
      checkCapacity( herm, 16UL );
      checkNonZeros( herm,  3UL );
      checkNonZeros( herm,  0UL, 1UL );
      checkNonZeros( herm,  1UL, 2UL );
      checkNonZeros( herm,  2UL, 0UL );
      checkNonZeros( herm,  3UL, 0UL );

      if( herm(0,0) != cplx(0,0) || herm(0,1) != cplx(1,-1) || herm(0,2) != cplx(0,0) || herm(0,3) != cplx(0,0) ||
          herm(1,0) != cplx(1,1) || herm(1,1) != cplx(2, 0) || herm(1,2) != cplx(0,0) || herm(1,3) != cplx(0,0) ||
          herm(2,0) != cplx(0,0) || herm(2,1) != cplx(0, 0) || herm(2,2) != cplx(0,0) || herm(2,3) != cplx(0,0) ||
          herm(3,0) != cplx(0,0) || herm(3,1) != cplx(0, 0) || herm(3,2) != cplx(0,0) || herm(3,3) != cplx(0,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Extending the matrix failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (0,0) (1,-1) (0,0) (0,0) )\n"
                                     "( (1,1) (2, 0) (0,0) (0,0) )\n"
                                     "( (0,0) (0, 0) (0,0) (0,0) )\n"
                                     "( (0,0) (0, 0) (0,0) (0,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major HermitianMatrix::extend()";

      // Initialization check
      OHT herm;

      checkRows    ( herm, 0UL );
      checkColumns ( herm, 0UL );
      checkNonZeros( herm, 0UL );

      // Extending the size of the matrix to 2x2
      herm.extend( 2UL );

      checkRows    ( herm, 2UL );
      checkColumns ( herm, 2UL );
      checkCapacity( herm, 4UL );
      checkNonZeros( herm, 0UL );
      checkNonZeros( herm, 0UL, 0UL );
      checkNonZeros( herm, 1UL, 0UL );

      if( herm(0,0) != cplx(0,0) || herm(0,1) != cplx(0,0) ||
          herm(1,0) != cplx(0,0) || herm(1,1) != cplx(0,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Extending the matrix failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (0,0) (0,0) )\n"
                                     "( (0,0) (0,0) )\n";
         throw std::runtime_error( oss.str() );
      }

      // Extending to 4x4 and preserving the elements
      herm(0,1) = cplx(1,-1);
      herm(1,1) = cplx(2, 0);
      herm.extend( 2UL, true );

      checkRows    ( herm,  4UL );
      checkColumns ( herm,  4UL );
      checkCapacity( herm, 16UL );
      checkNonZeros( herm,  3UL );
      checkNonZeros( herm,  0UL, 1UL );
      checkNonZeros( herm,  1UL, 2UL );
      checkNonZeros( herm,  2UL, 0UL );
      checkNonZeros( herm,  3UL, 0UL );

      if( herm(0,0) != cplx(0,0) || herm(0,1) != cplx(1,-1) || herm(0,2) != cplx(0,0) || herm(0,3) != cplx(0,0) ||
          herm(1,0) != cplx(1,1) || herm(1,1) != cplx(2, 0) || herm(1,2) != cplx(0,0) || herm(1,3) != cplx(0,0) ||
          herm(2,0) != cplx(0,0) || herm(2,1) != cplx(0, 0) || herm(2,2) != cplx(0,0) || herm(2,3) != cplx(0,0) ||
          herm(3,0) != cplx(0,0) || herm(3,1) != cplx(0, 0) || herm(3,2) != cplx(0,0) || herm(3,3) != cplx(0,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Extending the matrix failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (0,0) (1,-1) (0,0) (0,0) )\n"
                                     "( (1,1) (2, 0) (0,0) (0,0) )\n"
                                     "( (0,0) (0, 0) (0,0) (0,0) )\n"
                                     "( (0,0) (0, 0) (0,0) (0,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c reserve() member function of the HermitianMatrix specialization.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c reserve() member function of the HermitianMatrix
// specialization. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void DenseComplexTest::testReserve()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major HermitianMatrix::reserve()";

      // Initialization check
      HT herm;

      checkRows    ( herm, 0UL );
      checkColumns ( herm, 0UL );
      checkNonZeros( herm, 0UL );

      // Increasing the capacity of the matrix
      herm.reserve( 10UL );

      checkRows    ( herm,  0UL );
      checkColumns ( herm,  0UL );
      checkCapacity( herm, 10UL );
      checkNonZeros( herm,  0UL );

      // Further increasing the capacity of the matrix
      herm.reserve( 20UL );

      checkRows    ( herm,  0UL );
      checkColumns ( herm,  0UL );
      checkCapacity( herm, 20UL );
      checkNonZeros( herm,  0UL );
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major HermitianMatrix::reserve()";

      // Initialization check
      OHT herm;

      checkRows    ( herm, 0UL );
      checkColumns ( herm, 0UL );
      checkNonZeros( herm, 0UL );

      // Increasing the capacity of the matrix
      herm.reserve( 10UL );

      checkRows    ( herm,  0UL );
      checkColumns ( herm,  0UL );
      checkCapacity( herm, 10UL );
      checkNonZeros( herm,  0UL );

      // Further increasing the capacity of the matrix
      herm.reserve( 20UL );

      checkRows    ( herm,  0UL );
      checkColumns ( herm,  0UL );
      checkCapacity( herm, 20UL );
      checkNonZeros( herm,  0UL );
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c transpose() member function of the HermitianMatrix specialization.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c transpose() member function of the HermitianMatrix
// specialization. Additionally, it performs a test of self-transpose via the \c trans()
// function. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void DenseComplexTest::testTranspose()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major self-transpose via transpose()";

      HT herm( 4UL );
      herm(0,0) = cplx(1, 0);
      herm(0,2) = cplx(2,-1);
      herm(0,3) = cplx(3, 2);
      herm(1,1) = cplx(4, 0);
      herm(1,3) = cplx(5,-3);
      herm(2,2) = cplx(6, 0);
      herm(2,3) = cplx(7, 1);

      transpose( herm );

      checkRows    ( herm,  4UL );
      checkColumns ( herm,  4UL );
      checkCapacity( herm, 16UL );
      checkNonZeros( herm, 11UL );
      checkNonZeros( herm,  0UL, 3UL );
      checkNonZeros( herm,  1UL, 2UL );
      checkNonZeros( herm,  2UL, 3UL );
      checkNonZeros( herm,  3UL, 3UL );

      if( herm(0,0) != cplx(1, 0) || herm(0,1) != cplx(0, 0) || herm(0,2) != cplx(2, 1) || herm(0,3) != cplx(3,-2) ||
          herm(1,0) != cplx(0, 0) || herm(1,1) != cplx(4, 0) || herm(1,2) != cplx(0, 0) || herm(1,3) != cplx(5, 3) ||
          herm(2,0) != cplx(2,-1) || herm(2,1) != cplx(0, 0) || herm(2,2) != cplx(6, 0) || herm(2,3) != cplx(7,-1) ||
          herm(3,0) != cplx(3, 2) || herm(3,1) != cplx(5,-3) || herm(3,2) != cplx(7, 1) || herm(3,3) != cplx(0, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Transpose operation failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (1, 0) (0, 0) (2,1) (3,-2) )\n"
                                     "( (0, 0) (4, 0) (0,0) (5, 3) )\n"
                                     "( (2,-1) (0, 0) (6,0) (7,-1) )\n"
                                     "( (3, 2) (5,-3) (7,1) (0, 0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major self-transpose via trans()";

      HT herm( 4UL );
      herm(0,0) = cplx(1, 0);
      herm(0,2) = cplx(2,-1);
      herm(0,3) = cplx(3, 2);
      herm(1,1) = cplx(4, 0);
      herm(1,3) = cplx(5,-3);
      herm(2,2) = cplx(6, 0);
      herm(2,3) = cplx(7, 1);

      herm = trans( herm );

      checkRows    ( herm,  4UL );
      checkColumns ( herm,  4UL );
      checkCapacity( herm, 16UL );
      checkNonZeros( herm, 11UL );
      checkNonZeros( herm,  0UL, 3UL );
      checkNonZeros( herm,  1UL, 2UL );
      checkNonZeros( herm,  2UL, 3UL );
      checkNonZeros( herm,  3UL, 3UL );

      if( herm(0,0) != cplx(1, 0) || herm(0,1) != cplx(0, 0) || herm(0,2) != cplx(2, 1) || herm(0,3) != cplx(3,-2) ||
          herm(1,0) != cplx(0, 0) || herm(1,1) != cplx(4, 0) || herm(1,2) != cplx(0, 0) || herm(1,3) != cplx(5, 3) ||
          herm(2,0) != cplx(2,-1) || herm(2,1) != cplx(0, 0) || herm(2,2) != cplx(6, 0) || herm(2,3) != cplx(7,-1) ||
          herm(3,0) != cplx(3, 2) || herm(3,1) != cplx(5,-3) || herm(3,2) != cplx(7, 1) || herm(3,3) != cplx(0, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Transpose operation failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (1, 0) (0, 0) (2,1) (3,-2) )\n"
                                     "( (0, 0) (4, 0) (0,0) (5, 3) )\n"
                                     "( (2,-1) (0, 0) (6,0) (7,-1) )\n"
                                     "( (3, 2) (5,-3) (7,1) (0, 0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major self-transpose via transpose()";

      OHT herm( 4UL );
      herm(0,0) = cplx(1, 0);
      herm(0,2) = cplx(2,-1);
      herm(0,3) = cplx(3, 2);
      herm(1,1) = cplx(4, 0);
      herm(1,3) = cplx(5,-3);
      herm(2,2) = cplx(6, 0);
      herm(2,3) = cplx(7, 1);

      transpose( herm );

      checkRows    ( herm,  4UL );
      checkColumns ( herm,  4UL );
      checkCapacity( herm, 16UL );
      checkNonZeros( herm, 11UL );
      checkNonZeros( herm,  0UL, 3UL );
      checkNonZeros( herm,  1UL, 2UL );
      checkNonZeros( herm,  2UL, 3UL );
      checkNonZeros( herm,  3UL, 3UL );

      if( herm(0,0) != cplx(1, 0) || herm(0,1) != cplx(0, 0) || herm(0,2) != cplx(2, 1) || herm(0,3) != cplx(3,-2) ||
          herm(1,0) != cplx(0, 0) || herm(1,1) != cplx(4, 0) || herm(1,2) != cplx(0, 0) || herm(1,3) != cplx(5, 3) ||
          herm(2,0) != cplx(2,-1) || herm(2,1) != cplx(0, 0) || herm(2,2) != cplx(6, 0) || herm(2,3) != cplx(7,-1) ||
          herm(3,0) != cplx(3, 2) || herm(3,1) != cplx(5,-3) || herm(3,2) != cplx(7, 1) || herm(3,3) != cplx(0, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Transpose operation failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (1, 0) (0, 0) (2,1) (3,-2) )\n"
                                     "( (0, 0) (4, 0) (0,0) (5, 3) )\n"
                                     "( (2,-1) (0, 0) (6,0) (7,-1) )\n"
                                     "( (3, 2) (5,-3) (7,1) (0, 0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major self-transpose via trans()";

      OHT herm( 4UL );
      herm(0,0) = cplx(1, 0);
      herm(0,2) = cplx(2,-1);
      herm(0,3) = cplx(3, 2);
      herm(1,1) = cplx(4, 0);
      herm(1,3) = cplx(5,-3);
      herm(2,2) = cplx(6, 0);
      herm(2,3) = cplx(7, 1);

      herm = trans( herm );

      checkRows    ( herm,  4UL );
      checkColumns ( herm,  4UL );
      checkCapacity( herm, 16UL );
      checkNonZeros( herm, 11UL );
      checkNonZeros( herm,  0UL, 3UL );
      checkNonZeros( herm,  1UL, 2UL );
      checkNonZeros( herm,  2UL, 3UL );
      checkNonZeros( herm,  3UL, 3UL );

      if( herm(0,0) != cplx(1, 0) || herm(0,1) != cplx(0, 0) || herm(0,2) != cplx(2, 1) || herm(0,3) != cplx(3,-2) ||
          herm(1,0) != cplx(0, 0) || herm(1,1) != cplx(4, 0) || herm(1,2) != cplx(0, 0) || herm(1,3) != cplx(5, 3) ||
          herm(2,0) != cplx(2,-1) || herm(2,1) != cplx(0, 0) || herm(2,2) != cplx(6, 0) || herm(2,3) != cplx(7,-1) ||
          herm(3,0) != cplx(3, 2) || herm(3,1) != cplx(5,-3) || herm(3,2) != cplx(7, 1) || herm(3,3) != cplx(0, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Transpose operation failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (1, 0) (0, 0) (2,1) (3,-2) )\n"
                                     "( (0, 0) (4, 0) (0,0) (5, 3) )\n"
                                     "( (2,-1) (0, 0) (6,0) (7,-1) )\n"
                                     "( (3, 2) (5,-3) (7,1) (0, 0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c ctranspose() member function of the HermitianMatrix specialization.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c ctranspose() member function of the HermitianMatrix
// specialization. Additionally, it performs a test of self-transpose via the \c ctrans()
// function. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void DenseComplexTest::testCTranspose()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major self-transpose via ctranspose()";

      HT herm( 4UL );
      herm(0,0) = cplx(1, 0);
      herm(0,2) = cplx(2,-1);
      herm(0,3) = cplx(3, 2);
      herm(1,1) = cplx(4, 0);
      herm(1,3) = cplx(5,-3);
      herm(2,2) = cplx(6, 0);
      herm(2,3) = cplx(7, 1);

      ctranspose( herm );

      checkRows    ( herm,  4UL );
      checkColumns ( herm,  4UL );
      checkCapacity( herm, 16UL );
      checkNonZeros( herm, 11UL );
      checkNonZeros( herm,  0UL, 3UL );
      checkNonZeros( herm,  1UL, 2UL );
      checkNonZeros( herm,  2UL, 3UL );
      checkNonZeros( herm,  3UL, 3UL );

      if( herm(0,0) != cplx(1, 0) || herm(0,1) != cplx(0, 0) || herm(0,2) != cplx(2,-1) || herm(0,3) != cplx(3, 2) ||
          herm(1,0) != cplx(0, 0) || herm(1,1) != cplx(4, 0) || herm(1,2) != cplx(0, 0) || herm(1,3) != cplx(5,-3) ||
          herm(2,0) != cplx(2, 1) || herm(2,1) != cplx(0, 0) || herm(2,2) != cplx(6, 0) || herm(2,3) != cplx(7, 1) ||
          herm(3,0) != cplx(3,-2) || herm(3,1) != cplx(5, 3) || herm(3,2) != cplx(7,-1) || herm(3,3) != cplx(0, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Transpose operation failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (1, 0) (0, 0) (2,-1) (3, 2) )\n"
                                     "( (0, 0) (4, 0) (0, 0) (5,-3) )\n"
                                     "( (2, 1) (0, 0) (6, 0) (7, 1) )\n"
                                     "( (3,-2) (5, 3) (7,-1) (0, 0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major self-transpose via ctrans()";

      HT herm( 4UL );
      herm(0,0) = cplx(1, 0);
      herm(0,2) = cplx(2,-1);
      herm(0,3) = cplx(3, 2);
      herm(1,1) = cplx(4, 0);
      herm(1,3) = cplx(5,-3);
      herm(2,2) = cplx(6, 0);
      herm(2,3) = cplx(7, 1);

      herm = ctrans( herm );

      checkRows    ( herm,  4UL );
      checkColumns ( herm,  4UL );
      checkCapacity( herm, 16UL );
      checkNonZeros( herm, 11UL );
      checkNonZeros( herm,  0UL, 3UL );
      checkNonZeros( herm,  1UL, 2UL );
      checkNonZeros( herm,  2UL, 3UL );
      checkNonZeros( herm,  3UL, 3UL );

      if( herm(0,0) != cplx(1, 0) || herm(0,1) != cplx(0, 0) || herm(0,2) != cplx(2,-1) || herm(0,3) != cplx(3, 2) ||
          herm(1,0) != cplx(0, 0) || herm(1,1) != cplx(4, 0) || herm(1,2) != cplx(0, 0) || herm(1,3) != cplx(5,-3) ||
          herm(2,0) != cplx(2, 1) || herm(2,1) != cplx(0, 0) || herm(2,2) != cplx(6, 0) || herm(2,3) != cplx(7, 1) ||
          herm(3,0) != cplx(3,-2) || herm(3,1) != cplx(5, 3) || herm(3,2) != cplx(7,-1) || herm(3,3) != cplx(0, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Transpose operation failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (1, 0) (0, 0) (2,-1) (3, 2) )\n"
                                     "( (0, 0) (4, 0) (0, 0) (5,-3) )\n"
                                     "( (2, 1) (0, 0) (6, 0) (7, 1) )\n"
                                     "( (3,-2) (5, 3) (7,-1) (0, 0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major self-transpose via ctranspose()";

      OHT herm( 4UL );
      herm(0,0) = cplx(1, 0);
      herm(0,2) = cplx(2,-1);
      herm(0,3) = cplx(3, 2);
      herm(1,1) = cplx(4, 0);
      herm(1,3) = cplx(5,-3);
      herm(2,2) = cplx(6, 0);
      herm(2,3) = cplx(7, 1);

      ctranspose( herm );

      checkRows    ( herm,  4UL );
      checkColumns ( herm,  4UL );
      checkCapacity( herm, 16UL );
      checkNonZeros( herm, 11UL );
      checkNonZeros( herm,  0UL, 3UL );
      checkNonZeros( herm,  1UL, 2UL );
      checkNonZeros( herm,  2UL, 3UL );
      checkNonZeros( herm,  3UL, 3UL );

      if( herm(0,0) != cplx(1, 0) || herm(0,1) != cplx(0, 0) || herm(0,2) != cplx(2,-1) || herm(0,3) != cplx(3, 2) ||
          herm(1,0) != cplx(0, 0) || herm(1,1) != cplx(4, 0) || herm(1,2) != cplx(0, 0) || herm(1,3) != cplx(5,-3) ||
          herm(2,0) != cplx(2, 1) || herm(2,1) != cplx(0, 0) || herm(2,2) != cplx(6, 0) || herm(2,3) != cplx(7, 1) ||
          herm(3,0) != cplx(3,-2) || herm(3,1) != cplx(5, 3) || herm(3,2) != cplx(7,-1) || herm(3,3) != cplx(0, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Transpose operation failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (1, 0) (0, 0) (2,-1) (3, 2) )\n"
                                     "( (0, 0) (4, 0) (0, 0) (5,-3) )\n"
                                     "( (2, 1) (0, 0) (6, 0) (7, 1) )\n"
                                     "( (3,-2) (5, 3) (7,-1) (0, 0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major self-transpose via ctrans()";

      OHT herm( 4UL );
      herm(0,0) = cplx(1, 0);
      herm(0,2) = cplx(2,-1);
      herm(0,3) = cplx(3, 2);
      herm(1,1) = cplx(4, 0);
      herm(1,3) = cplx(5,-3);
      herm(2,2) = cplx(6, 0);
      herm(2,3) = cplx(7, 1);

      herm = ctrans( herm );

      checkRows    ( herm,  4UL );
      checkColumns ( herm,  4UL );
      checkCapacity( herm, 16UL );
      checkNonZeros( herm, 11UL );
      checkNonZeros( herm,  0UL, 3UL );
      checkNonZeros( herm,  1UL, 2UL );
      checkNonZeros( herm,  2UL, 3UL );
      checkNonZeros( herm,  3UL, 3UL );

      if( herm(0,0) != cplx(1, 0) || herm(0,1) != cplx(0, 0) || herm(0,2) != cplx(2,-1) || herm(0,3) != cplx(3, 2) ||
          herm(1,0) != cplx(0, 0) || herm(1,1) != cplx(4, 0) || herm(1,2) != cplx(0, 0) || herm(1,3) != cplx(5,-3) ||
          herm(2,0) != cplx(2, 1) || herm(2,1) != cplx(0, 0) || herm(2,2) != cplx(6, 0) || herm(2,3) != cplx(7, 1) ||
          herm(3,0) != cplx(3,-2) || herm(3,1) != cplx(5, 3) || herm(3,2) != cplx(7,-1) || herm(3,3) != cplx(0, 0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Transpose operation failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (1, 0) (0, 0) (2,-1) (3, 2) )\n"
                                     "( (0, 0) (4, 0) (0, 0) (5,-3) )\n"
                                     "( (2, 1) (0, 0) (6, 0) (7, 1) )\n"
                                     "( (3,-2) (5, 3) (7,-1) (0, 0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c swap() functionality of the HermitianMatrix specialization.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c swap() function of the HermitianMatrix specialization.
// In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void DenseComplexTest::testSwap()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major HermitianMatrix swap";

      HT herm1( 2UL );
      herm1(0,0) = cplx(1,0);
      herm1(0,1) = cplx(2,1);
      herm1(1,1) = cplx(3,0);

      HT herm2( 2UL );
      herm2(0,0) = cplx(4,0);
      herm2(0,1) = cplx(5,1);

      swap( herm1, herm2 );

      checkRows    ( herm1, 2UL );
      checkColumns ( herm1, 2UL );
      checkCapacity( herm1, 4UL );
      checkNonZeros( herm1, 3UL );
      checkNonZeros( herm1, 0UL, 2UL );
      checkNonZeros( herm1, 1UL, 1UL );

      if( herm1(0,0) != cplx(4, 0) || herm1(0,1) != cplx(5,1) ||
          herm1(1,0) != cplx(5,-1) || herm1(1,1) != cplx(0,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Swapping the first matrix failed\n"
             << " Details:\n"
             << "   Result:\n" << herm1 << "\n"
             << "   Expected result:\n( (4, 0) (5,1) )\n"
                                     "( (5,-1) (0,0) )\n";
         throw std::runtime_error( oss.str() );
      }

      checkRows    ( herm2, 2UL );
      checkColumns ( herm2, 2UL );
      checkCapacity( herm2, 4UL );
      checkNonZeros( herm2, 4UL );
      checkNonZeros( herm2, 0UL, 2UL );
      checkNonZeros( herm2, 1UL, 2UL );

      if( herm2(0,0) != cplx(1, 0) || herm2(0,1) != cplx(2,1) ||
          herm2(1,0) != cplx(2,-1) || herm2(1,1) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Swapping the second matrix failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( (1, 0) (2,1) )\n"
                                     "( (2,-1) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major HermitianMatrix swap";

      OHT herm1( 2UL );
      herm1(0,0) = cplx(1,0);
      herm1(0,1) = cplx(2,1);
      herm1(1,1) = cplx(3,0);

      OHT herm2( 2UL );
      herm2(0,0) = cplx(4,0);
      herm2(0,1) = cplx(5,1);

      swap( herm1, herm2 );

      checkRows    ( herm1, 2UL );
      checkColumns ( herm1, 2UL );
      checkCapacity( herm1, 4UL );
      checkNonZeros( herm1, 3UL );
      checkNonZeros( herm1, 0UL, 2UL );
      checkNonZeros( herm1, 1UL, 1UL );

      if( herm1(0,0) != cplx(4, 0) || herm1(0,1) != cplx(5,1) ||
          herm1(1,0) != cplx(5,-1) || herm1(1,1) != cplx(0,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Swapping the first matrix failed\n"
             << " Details:\n"
             << "   Result:\n" << herm1 << "\n"
             << "   Expected result:\n( (4, 0) (5,1) )\n"
                                     "( (5,-1) (0,0) )\n";
         throw std::runtime_error( oss.str() );
      }

      checkRows    ( herm2, 2UL );
      checkColumns ( herm2, 2UL );
      checkCapacity( herm2, 4UL );
      checkNonZeros( herm2, 4UL );
      checkNonZeros( herm2, 0UL, 2UL );
      checkNonZeros( herm2, 1UL, 2UL );

      if( herm2(0,0) != cplx(1, 0) || herm2(0,1) != cplx(2,1) ||
          herm2(1,0) != cplx(2,-1) || herm2(1,1) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Swapping the second matrix failed\n"
             << " Details:\n"
             << "   Result:\n" << herm2 << "\n"
             << "   Expected result:\n( (1, 0) (2,1) )\n"
                                     "( (2,-1) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c isDefault() function with the HermitianMatrix specialization.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c isDefault() function with the HermitianMatrix
// specialization. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void DenseComplexTest::testIsDefault()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isDefault() function";

      // isDefault with 0x0 matrix
      {
         HT herm;

         if( isDefault( herm ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << herm << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isDefault with default matrix
      {
         HT herm( 3UL );

         if( isDefault( herm(0,1) ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Matrix element:\n" << herm(0,1) << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( isDefault( herm ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << herm << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isDefault with non-default matrix
      {
         HT herm( 3UL );
         herm(0,1) = cplx(1,1);

         if( isDefault( herm(0,1) ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Matrix element:\n" << herm(0,1) << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( isDefault( herm ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << herm << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isDefault() function";

      // isDefault with 0x0 matrix
      {
         OHT herm;

         if( isDefault( herm ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << herm << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isDefault with default matrix
      {
         OHT herm( 3UL );

         if( isDefault( herm(0,1) ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Matrix element:\n" << herm(0,1) << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( isDefault( herm ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << herm << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isDefault with non-default matrix
      {
         OHT herm( 3UL );
         herm(0,1) = cplx(1,1);

         if( isDefault( herm(0,1) ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Matrix element:\n" << herm(0,1) << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( isDefault( herm ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << herm << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c submatrix() function with the HermitianMatrix specialization.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c submatrix() function with the HermitianMatrix
// specialization. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void DenseComplexTest::testSubmatrix()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major submatrix() function";

      typedef blaze::DenseSubmatrix<HT>  SMT;

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      SMT sm = submatrix( herm, 0UL, 1UL, 2UL, 2UL );

      if( sm(0,1) != cplx(7,3) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator access failed\n"
             << " Details:\n"
             << "   Result: " << sm(0,1) << "\n"
             << "   Expected result: (7,3)\n";
         throw std::runtime_error( oss.str() );
      }

      SMT::Iterator it = sm.begin(0UL);

      if( it == sm.end(0UL) || *it != cplx(-4,-1) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Iterator access failed\n"
             << " Details:\n"
             << "   Result: " << *it << "\n"
             << "   Expected result: (-4,-1)\n";
         throw std::runtime_error( oss.str() );
      }

      sm(1,1) = cplx(-5,2);

      if( sm(0,0) != cplx(-4,-1) || sm(0,1) != cplx( 7,3) ||
          sm(1,0) != cplx( 2, 0) || sm(1,1) != cplx(-5,2) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Submatrix access failed\n"
             << " Details:\n"
             << "   Result:\n" << sm << "\n"
             << "   Expected result:\n( (-4,-1) ( 7,3) )\n"
                                     "( ( 2, 0) (-5,2) )\n";
         throw std::runtime_error( oss.str() );
      }

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-4,-1) || herm(0,2) != cplx( 7,3) ||
          herm(1,0) != cplx(-4, 1) || herm(1,1) != cplx( 2, 0) || herm(1,2) != cplx(-5,2) ||
          herm(2,0) != cplx( 7,-3) || herm(2,1) != cplx(-5,-2) || herm(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Submatrix access failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) ( 7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (-5,2) )\n"
                                     "( ( 7,-3) (-5,-2) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }

      reset( sm );

      if( sm(0,0) != cplx(0,0) || sm(0,1) != cplx(0,0) ||
          sm(1,0) != cplx(0,0) || sm(1,1) != cplx(0,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Submatrix reset failed\n"
             << " Details:\n"
             << "   Result:\n" << sm << "\n"
             << "   Expected result:\n( (0,0) (0,0) )\n"
                                     "( (0,0) (0,0) )\n";
         throw std::runtime_error( oss.str() );
      }

      if( herm(0,0) != cplx(1,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(0,0) ||
          herm(1,0) != cplx(0,0) || herm(1,1) != cplx(0,0) || herm(1,2) != cplx(0,0) ||
          herm(2,0) != cplx(0,0) || herm(2,1) != cplx(0,0) || herm(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Submatrix reset failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (1,0) (0,0) (0,0) )\n"
                                     "( (0,0) (0,0) (0,0) )\n"
                                     "( (0,0) (0,0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major submatrix() function";

      typedef blaze::DenseSubmatrix<OHT>  SMT;

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      SMT sm = submatrix( herm, 0UL, 1UL, 2UL, 2UL );

      if( sm(0,1) != cplx(7,3) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator access failed\n"
             << " Details:\n"
             << "   Result: " << sm(0,1) << "\n"
             << "   Expected result: (7,3)\n";
         throw std::runtime_error( oss.str() );
      }

      SMT::Iterator it = sm.begin(0UL);

      if( it == sm.end(0UL) || *it != cplx(-4,-1) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Iterator access failed\n"
             << " Details:\n"
             << "   Result: " << *it << "\n"
             << "   Expected result: (-4,-1)\n";
         throw std::runtime_error( oss.str() );
      }

      sm(1,1) = cplx(-5,2);

      if( sm(0,0) != cplx(-4,-1) || sm(0,1) != cplx( 7,3) ||
          sm(1,0) != cplx( 2, 0) || sm(1,1) != cplx(-5,2) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Submatrix access failed\n"
             << " Details:\n"
             << "   Result:\n" << sm << "\n"
             << "   Expected result:\n( (-4,-1) ( 7,3) )\n"
                                     "( ( 2, 0) (-5,2) )\n";
         throw std::runtime_error( oss.str() );
      }

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-4,-1) || herm(0,2) != cplx( 7,3) ||
          herm(1,0) != cplx(-4, 1) || herm(1,1) != cplx( 2, 0) || herm(1,2) != cplx(-5,2) ||
          herm(2,0) != cplx( 7,-3) || herm(2,1) != cplx(-5,-2) || herm(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Submatrix access failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) ( 7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (-5,2) )\n"
                                     "( ( 7,-3) (-5,-2) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }

      reset( sm );

      if( sm(0,0) != cplx(0,0) || sm(0,1) != cplx(0,0) ||
          sm(1,0) != cplx(0,0) || sm(1,1) != cplx(0,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Submatrix reset failed\n"
             << " Details:\n"
             << "   Result:\n" << sm << "\n"
             << "   Expected result:\n( (0,0) (0,0) )\n"
                                     "( (0,0) (0,0) )\n";
         throw std::runtime_error( oss.str() );
      }

      if( herm(0,0) != cplx(1,0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(0,0) ||
          herm(1,0) != cplx(0,0) || herm(1,1) != cplx(0,0) || herm(1,2) != cplx(0,0) ||
          herm(2,0) != cplx(0,0) || herm(2,1) != cplx(0,0) || herm(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Submatrix reset failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (1,0) (0,0) (0,0) )\n"
                                     "( (0,0) (0,0) (0,0) )\n"
                                     "( (0,0) (0,0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c row() function with the HermitianMatrix specialization.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c row() function with the HermitianMatrix specialization.
// In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void DenseComplexTest::testRow()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major row() function";

      typedef blaze::DenseRow<HT>  RT;

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      RT row1 = row( herm, 1UL );

      if( row1[1] != cplx(2,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator access failed\n"
             << " Details:\n"
             << "   Result: " << row1[1] << "\n"
             << "   Expected result: (2,0)\n";
         throw std::runtime_error( oss.str() );
      }

      RT::Iterator it = row1.begin();

      if( it == row1.end() || *it != cplx(-4,1) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Iterator access failed\n"
             << " Details:\n"
             << "   Result: " << *it << "\n"
             << "   Expected result: (-4,1)\n";
         throw std::runtime_error( oss.str() );
      }

      row1[2] = cplx(-5,2);

      if( row1[0] != cplx(-4,1) || row1[1] != cplx(2,0) || row1[2] != cplx(-5,2) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Row access failed\n"
             << " Details:\n"
             << "   Result:\n" << row1 << "\n"
             << "   Expected result:\n( (-4,1) ( 2,0) (-5,2) )\n";
         throw std::runtime_error( oss.str() );
      }

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-4,-1) || herm(0,2) != cplx( 7,3) ||
          herm(1,0) != cplx(-4, 1) || herm(1,1) != cplx( 2, 0) || herm(1,2) != cplx(-5,2) ||
          herm(2,0) != cplx( 7,-3) || herm(2,1) != cplx(-5,-2) || herm(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Row access failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) ( 7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (-5,2) )\n"
                                     "( ( 7,-3) (-5,-2) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }

      reset( row1 );

      if( row1[0] != cplx(0,0) || row1[1] != cplx(0,0) || row1[2] != cplx(0,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Row reset failed\n"
             << " Details:\n"
             << "   Result:\n" << row1 << "\n"
             << "   Expected result:\n( (0,0) (0,0) (0,0) )\n";
         throw std::runtime_error( oss.str() );
      }

      if( herm(0,0) != cplx(1, 0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(7,3) ||
          herm(1,0) != cplx(0, 0) || herm(1,1) != cplx(0,0) || herm(1,2) != cplx(0,0) ||
          herm(2,0) != cplx(7,-3) || herm(2,1) != cplx(0,0) || herm(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Row reset failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (1, 0) (0,0) (7,3) )\n"
                                     "( (0, 0) (0,0) (0,0) )\n"
                                     "( (7,-3) (0,0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major row() function";

      typedef blaze::DenseRow<OHT>  RT;

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      RT row1 = row( herm, 1UL );

      if( row1[1] != cplx(2,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator access failed\n"
             << " Details:\n"
             << "   Result: " << row1[1] << "\n"
             << "   Expected result: (2,0)\n";
         throw std::runtime_error( oss.str() );
      }

      RT::Iterator it = row1.begin();

      if( it == row1.end() || *it != cplx(-4,1) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Iterator access failed\n"
             << " Details:\n"
             << "   Result: " << *it << "\n"
             << "   Expected result: (-4,1)\n";
         throw std::runtime_error( oss.str() );
      }

      row1[2] = cplx(-5,2);

      if( row1[0] != cplx(-4,1) || row1[1] != cplx(2,0) || row1[2] != cplx(-5,2) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Row access failed\n"
             << " Details:\n"
             << "   Result:\n" << row1 << "\n"
             << "   Expected result:\n( (-4,1) ( 2,0) (-5,2) )\n";
         throw std::runtime_error( oss.str() );
      }

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-4,-1) || herm(0,2) != cplx( 7,3) ||
          herm(1,0) != cplx(-4, 1) || herm(1,1) != cplx( 2, 0) || herm(1,2) != cplx(-5,2) ||
          herm(2,0) != cplx( 7,-3) || herm(2,1) != cplx(-5,-2) || herm(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Row access failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) ( 7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (-5,2) )\n"
                                     "( ( 7,-3) (-5,-2) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }

      reset( row1 );

      if( row1[0] != cplx(0,0) || row1[1] != cplx(0,0) || row1[2] != cplx(0,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Row reset failed\n"
             << " Details:\n"
             << "   Result:\n" << row1 << "\n"
             << "   Expected result:\n( (0,0) (0,0) (0,0) )\n";
         throw std::runtime_error( oss.str() );
      }

      if( herm(0,0) != cplx(1, 0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(7,3) ||
          herm(1,0) != cplx(0, 0) || herm(1,1) != cplx(0,0) || herm(1,2) != cplx(0,0) ||
          herm(2,0) != cplx(7,-3) || herm(2,1) != cplx(0,0) || herm(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Row reset failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (1, 0) (0,0) (7,3) )\n"
                                     "( (0, 0) (0,0) (0,0) )\n"
                                     "( (7,-3) (0,0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c column() function with the HermitianMatrix specialization.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c column() function with the HermitianMatrix
// specialization. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void DenseComplexTest::testColumn()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major column() function";

      typedef blaze::DenseColumn<HT>  CT;

      HT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      CT col1 = column( herm, 1UL );

      if( col1[1] != cplx(2,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator access failed\n"
             << " Details:\n"
             << "   Result: " << col1[1] << "\n"
             << "   Expected result: (2,0)\n";
         throw std::runtime_error( oss.str() );
      }

      CT::Iterator it = col1.begin();

      if( it == col1.end() || *it != cplx(-4,-1) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Iterator access failed\n"
             << " Details:\n"
             << "   Result: " << *it << "\n"
             << "   Expected result: (-4,-1)\n";
         throw std::runtime_error( oss.str() );
      }

      col1[2] = cplx(-5,-2);

      if( col1[0] != cplx(-4,-1) || col1[1] != cplx(2,0) || col1[2] != cplx(-5,-2) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Column access failed\n"
             << " Details:\n"
             << "   Result:\n" << col1 << "\n"
             << "   Expected result:\n( (-4,-1) ( 2,0) (-5,-2) )\n";
         throw std::runtime_error( oss.str() );
      }

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-4,-1) || herm(0,2) != cplx( 7,3) ||
          herm(1,0) != cplx(-4, 1) || herm(1,1) != cplx( 2, 0) || herm(1,2) != cplx(-5,2) ||
          herm(2,0) != cplx( 7,-3) || herm(2,1) != cplx(-5,-2) || herm(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Column access failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) ( 7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (-5,2) )\n"
                                     "( ( 7,-3) (-5,-2) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }

      reset( col1 );

      if( col1[0] != cplx(0,0) || col1[1] != cplx(0,0) || col1[2] != cplx(0,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Column reset failed\n"
             << " Details:\n"
             << "   Result:\n" << col1 << "\n"
             << "   Expected result:\n( (0,0) (0,0) (0,0) )\n";
         throw std::runtime_error( oss.str() );
      }

      if( herm(0,0) != cplx(1, 0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(7,3) ||
          herm(1,0) != cplx(0, 0) || herm(1,1) != cplx(0,0) || herm(1,2) != cplx(0,0) ||
          herm(2,0) != cplx(7,-3) || herm(2,1) != cplx(0,0) || herm(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Column reset failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (1, 0) (0,0) (7,3) )\n"
                                     "( (0, 0) (0,0) (0,0) )\n"
                                     "( (7,-3) (0,0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major column() function";

      typedef blaze::DenseColumn<OHT>  CT;

      OHT herm( 3UL );
      herm(0,0) = cplx( 1, 0);
      herm(0,1) = cplx(-4,-1);
      herm(0,2) = cplx( 7, 3);
      herm(1,1) = cplx( 2, 0);
      herm(2,2) = cplx( 3, 0);

      CT col1 = column( herm, 1UL );

      if( col1[1] != cplx(2,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator access failed\n"
             << " Details:\n"
             << "   Result: " << col1[1] << "\n"
             << "   Expected result: (2,0)\n";
         throw std::runtime_error( oss.str() );
      }

      CT::Iterator it = col1.begin();

      if( it == col1.end() || *it != cplx(-4,-1) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Iterator access failed\n"
             << " Details:\n"
             << "   Result: " << *it << "\n"
             << "   Expected result: (-4,-1)\n";
         throw std::runtime_error( oss.str() );
      }

      col1[2] = cplx(-5,-2);

      if( col1[0] != cplx(-4,-1) || col1[1] != cplx(2,0) || col1[2] != cplx(-5,-2) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Column access failed\n"
             << " Details:\n"
             << "   Result:\n" << col1 << "\n"
             << "   Expected result:\n( (-4,-1) ( 2,0) (-5,-2) )\n";
         throw std::runtime_error( oss.str() );
      }

      if( herm(0,0) != cplx( 1, 0) || herm(0,1) != cplx(-4,-1) || herm(0,2) != cplx( 7,3) ||
          herm(1,0) != cplx(-4, 1) || herm(1,1) != cplx( 2, 0) || herm(1,2) != cplx(-5,2) ||
          herm(2,0) != cplx( 7,-3) || herm(2,1) != cplx(-5,-2) || herm(2,2) != cplx( 3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Column access failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( ( 1, 0) (-4,-1) ( 7,3) )\n"
                                     "( (-4, 1) ( 2, 0) (-5,2) )\n"
                                     "( ( 7,-3) (-5,-2) ( 3,0) )\n";
         throw std::runtime_error( oss.str() );
      }

      reset( col1 );

      if( col1[0] != cplx(0,0) || col1[1] != cplx(0,0) || col1[2] != cplx(0,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Column reset failed\n"
             << " Details:\n"
             << "   Result:\n" << col1 << "\n"
             << "   Expected result:\n( (0,0) (0,0) (0,0) )\n";
         throw std::runtime_error( oss.str() );
      }

      if( herm(0,0) != cplx(1, 0) || herm(0,1) != cplx(0,0) || herm(0,2) != cplx(7,3) ||
          herm(1,0) != cplx(0, 0) || herm(1,1) != cplx(0,0) || herm(1,2) != cplx(0,0) ||
          herm(2,0) != cplx(7,-3) || herm(2,1) != cplx(0,0) || herm(2,2) != cplx(3,0) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Column reset failed\n"
             << " Details:\n"
             << "   Result:\n" << herm << "\n"
             << "   Expected result:\n( (1, 0) (0,0) (7,3) )\n"
                                     "( (0, 0) (0,0) (0,0) )\n"
                                     "( (7,-3) (0,0) (3,0) )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************

} // namespace hermitianmatrix

} // namespace mathtest

} // namespace blazetest




//=================================================================================================
//
//  MAIN FUNCTION
//
//=================================================================================================

//*************************************************************************************************
int main()
{
   std::cout << "   Running HermitianMatrix dense complex test..." << std::endl;

   try
   {
      RUN_HERMITIANMATRIX_DENSECOMPLEX_TEST;
   }
   catch( std::exception& ex ) {
      std::cerr << "\n\n ERROR DETECTED during HermitianMatrix dense complex test:\n"
                << ex.what() << "\n";
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
}
//*************************************************************************************************
