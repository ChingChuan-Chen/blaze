//=================================================================================================
/*!
//  \file src/mathtest/sparsematrix/OperationTest.cpp
//  \brief Source file for the SparseMatrix functionality operation test
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
#include <blaze/math/sparse/SparseMatrix.h>
#include <blaze/math/CompressedMatrix.h>
#include <blaze/math/DiagonalMatrix.h>
#include <blaze/math/HermitianMatrix.h>
#include <blaze/math/LowerMatrix.h>
#include <blaze/math/StrictlyLowerMatrix.h>
#include <blaze/math/StrictlyUpperMatrix.h>
#include <blaze/math/SymmetricMatrix.h>
#include <blaze/math/UniLowerMatrix.h>
#include <blaze/math/UniUpperMatrix.h>
#include <blaze/math/UpperMatrix.h>
#include <blazetest/mathtest/sparsematrix/OperationTest.h>


namespace blazetest {

namespace mathtest {

namespace sparsematrix {

//=================================================================================================
//
//  CONSTRUCTORS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Constructor for the OperationTest class test.
//
// \exception std::runtime_error Operation error detected.
*/
OperationTest::OperationTest()
{
   testIsNan();
   testIsSquare();
   testIsSymmetric();
   testIsHermitian();
   testIsUniform();
   testIsLower();
   testIsUniLower();
   testIsStrictlyLower();
   testIsUpper();
   testIsUniUpper();
   testIsStrictlyUpper();
   testIsDiagonal();
   testIsIdentity();
   testMinimum();
   testMaximum();
}
//*************************************************************************************************




//=================================================================================================
//
//  TEST FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Test of the \c isnan() function for sparse matrices.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c isnan() function for sparse matrices. In case an
// error is detected, a \a std::runtime_error exception is thrown.
*/
void OperationTest::testIsNan()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isnan()";

      // isnan with 0x0 matrix
      {
         blaze::CompressedMatrix<float,blaze::rowMajor> mat;

         checkRows    ( mat, 0UL );
         checkColumns ( mat, 0UL );
         checkNonZeros( mat, 0UL );

         if( blaze::isnan( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isnan evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isnan with empty 3x5 matrix
      {
         blaze::CompressedMatrix<float,blaze::rowMajor> mat( 3UL, 5UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 5UL );
         checkNonZeros( mat, 0UL );

         if( blaze::isnan( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isnan evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isnan with filled 4x2 matrix
      {
         blaze::CompressedMatrix<float,blaze::rowMajor> mat( 4UL, 2UL );
         mat(1,1) =  1.0F;
         mat(2,0) = -2.0F;
         mat(2,1) =  3.0F;
         mat(3,0) =  4.0F;

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 2UL );
         checkNonZeros( mat, 4UL );

         if( blaze::isnan( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isnan evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isnan()";

      // isnan with 0x0 matrix
      {
         blaze::CompressedMatrix<float,blaze::columnMajor> mat;

         checkRows    ( mat, 0UL );
         checkColumns ( mat, 0UL );
         checkNonZeros( mat, 0UL );

         if( blaze::isnan( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isnan evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isnan with empty 3x5 matrix
      {
         blaze::CompressedMatrix<float,blaze::columnMajor> mat( 3UL, 5UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 5UL );
         checkNonZeros( mat, 0UL );

         if( blaze::isnan( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isnan evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isnan with filled 4x2 matrix
      {
         blaze::CompressedMatrix<float,blaze::columnMajor> mat( 4UL, 2UL );
         mat(1,1) =  1.0F;
         mat(2,0) = -2.0F;
         mat(2,1) =  3.0F;
         mat(3,0) =  4.0F;

         checkRows    ( mat, 4UL );
         checkColumns ( mat, 2UL );
         checkNonZeros( mat, 4UL );

         if( blaze::isnan( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isnan evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c isSquare() function for sparse matrices.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c isSquare() function for sparse matrices. In case an
// error is detected, a \a std::runtime_error exception is thrown.
*/
void OperationTest::testIsSquare()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isSquare()";

      // Square matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL );

         checkRows   ( mat, 3UL );
         checkColumns( mat, 3UL );

         if( isSquare( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSquare evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-square matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 2UL, 3UL, 0 );

         checkRows   ( mat, 2UL );
         checkColumns( mat, 3UL );

         if( isSquare( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSquare evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isSquare()";

      // Square matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 0 );

         checkRows   ( mat, 3UL );
         checkColumns( mat, 3UL );

         if( isSquare( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSquare evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-square matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 2UL, 0 );

         checkRows   ( mat, 3UL );
         checkColumns( mat, 2UL );

         if( isSquare( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSquare evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c isSymmetric() function for sparse matrices.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c isSymmetric() function for sparse matrices. In case an
// error is detected, a \a std::runtime_error exception is thrown.
*/
void OperationTest::testIsSymmetric()
{
   //=====================================================================================
   // Row-major general matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isSymmetric() (general matrix)";

      // Non-square matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 2UL, 3UL );

         checkRows    ( mat, 2UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );

         if( isSymmetric( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Default initialized matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;
         mat.insert( 1UL, 2UL, 0 );
         mat.insert( 2UL, 0UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-symmetric matrix (additional element in the lower part)
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,0) = 4;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 4UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isSymmetric( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-symmetric matrix (additional element in the upper part)
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 4UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isSymmetric( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(2,0) = 4;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major symmetric matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isSymmetric() (symmetric matrix)";

      // Default symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major Hermitian matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isSymmetric() (Hermitian matrix)";

      // Default Hermitian matrix (built-in data type)
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric Hermitian matrix (built-in data type)
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Default Hermitian matrix (complex data type)
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric Hermitian matrix (complex data type)
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).real( 4 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // General Hermitian matrix (complex data type)
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).imag( 4 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isSymmetric( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major lower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isSymmetric() (lower matrix)";

      // Default lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,0) = 4;
         mat(1,1) = 2;
         mat(2,0) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isSymmetric( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major unilower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isSymmetric() (unilower matrix)";

      // Default unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isSymmetric( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major strictly lower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isSymmetric() (strictly lower matrix)";

      // Default strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isSymmetric( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major upper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isSymmetric() (upper matrix)";

      // Default upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(1,2) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isSymmetric( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major uniupper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isSymmetric() (uniupper matrix)";

      // Default uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isSymmetric( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major strictly upper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isSymmetric() (strictly upper matrix)";

      // Default strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isSymmetric( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major diagonal matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isSymmetric() (diagonal matrix)";

      // Default diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major general matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isSymmetric() (general matrix)";

      // Non-square matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 2UL, 3UL );

         checkRows    ( mat, 2UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isSymmetric( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Default initialized matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;
         mat.insert( 1UL, 2UL, 0 );
         mat.insert( 2UL, 0UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-symmetric matrix (additional element in the lower part)
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 4UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,0) = 4;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 4UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isSymmetric( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-symmetric matrix (additional element in the upper part)
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 4UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 4UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isSymmetric( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(2,0) = 4;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major symmetric matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isSymmetric() (symmetric matrix)";

      // Default symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major Hermitian matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isSymmetric() (Hermitian matrix)";

      // Default Hermitian matrix (built-in data type)
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric Hermitian matrix (built-in data type)
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Default Hermitian matrix (complex data type)
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric Hermitian matrix (complex data type)
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).real( 4 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // General Hermitian matrix (complex data type)
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).imag( 4 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isSymmetric( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major lower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isSymmetric() (lower matrix)";

      // Default lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,0) = 4;
         mat(1,1) = 2;
         mat(2,0) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isSymmetric( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major unilower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isSymmetric() (unilower matrix)";

      // Default unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isSymmetric( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major strictly lower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isSymmetric() (strictly lower matrix)";

      // Default strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isSymmetric( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major upper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isSymmetric() (upper matrix)";

      // Default upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(1,2) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isSymmetric( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major uniupper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isSymmetric() (uniupper matrix)";

      // Default uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isSymmetric( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major strictly upper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isSymmetric() (strictly upper matrix)";

      // Default strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isSymmetric( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major diagonal matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isSymmetric() (diagonal matrix)";

      // Default diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isSymmetric( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSymmetric evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c isHermitian() function for sparse matrices.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c isHermitian() function for sparse matrices. In case an
// error is detected, a \a std::runtime_error exception is thrown.
*/
void OperationTest::testIsHermitian()
{
   //=====================================================================================
   // Row-major general matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isHermitian() (general matrix)";

      // Non-square matrix
      {
         blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 2UL, 3UL );

         checkRows    ( mat, 2UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );

         if( isHermitian( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Default initialized matrix
      {
         blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-real diagonal element
      {
         blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 1UL );
         mat(1,1).imag( 1 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 1UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isHermitian( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-Hermitian matrix (additional element in the lower part)
      {
         blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 4UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 2 );
         mat(2,0).real( 4 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isHermitian( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-Hermitian matrix (additional element in the upper part)
      {
         blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 4UL );
         mat(0,0).real( 1 );
         mat(0,2).real( 4 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isHermitian( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-Hermitian matrix (invalid pair of elements)
      {
         blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0).real( 1 );
         mat(0,2).imag( 4 );
         mat(1,1).real( 2 );
         mat(2,0).imag( 4 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isHermitian( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Hermitian matrix
      {
         blaze::CompressedMatrix<cplx,blaze::rowMajor> mat( 3UL, 3UL, 7UL );
         mat(0,0).real(  1 );
         mat(0,2).imag(  4 );
         mat(1,1).real(  2 );
         mat(2,0).imag( -4 );
         mat(2,2).real(  3 );
         mat.insert( 0UL, 1UL, 0 );
         mat.insert( 1UL, 0UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 7UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major symmetric matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isHermitian() (symmetric matrix)";

      // Default symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric matrix (built-in data type)
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric matrix (complex data type)
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).imag( 4 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isHermitian( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major Hermitian matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isHermitian() (Hermitian matrix)";

      // Default Hermitian matrix (built-in data type)
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric Hermitian matrix (built-in data type)
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Default Hermitian matrix (complex data type)
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric Hermitian matrix (complex data type)
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).real( 4 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // General Hermitian matrix (complex data type)
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).imag( 4 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major lower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isHermitian() (lower matrix)";

      // Default lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,0).imag( 4 );
         mat(1,1).real( 2 );
         mat(2,0).imag( 5 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isHermitian( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major unilower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isHermitian() (unilower matrix)";

      // Default unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(1,0).imag( 4 );
         mat(2,0).imag( 5 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isHermitian( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major strictly lower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isHermitian() (strictly lower matrix)";

      // Default strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(1,0).imag( 4 );
         mat(2,0).imag( 5 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isHermitian( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major upper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isHermitian() (upper matrix)";

      // Default upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).imag( 4 );
         mat(1,1).real( 2 );
         mat(1,2).imag( 5 );
         mat(2,2).real( 1 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isHermitian( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major uniupper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isHermitian() (uniupper matrix)";

      // Default uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,2).imag( 4 );
         mat(1,2).imag( 5 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isHermitian( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major strictly upper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isHermitian() (strictly upper matrix)";

      // Default strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,2).imag( 4 );
         mat(1,2).imag( 5 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isHermitian( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major diagonal matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isHermitian() (diagonal matrix)";

      // Default diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major general matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isHermitian() (general matrix)";

      // Non-square matrix
      {
         blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 2UL, 3UL );

         checkRows    ( mat, 2UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );

         if( isHermitian( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Default initialized matrix
      {
         blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-real diagonal element
      {
         blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 1UL );
         mat(1,1).imag( 1 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 1UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isHermitian( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-Hermitian matrix (additional element in the lower part)
      {
         blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 4UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 2 );
         mat(2,0).real( 4 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isHermitian( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-Hermitian matrix (additional element in the upper part)
      {
         blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 4UL );
         mat(0,0).real( 1 );
         mat(0,2).real( 4 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isHermitian( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-Hermitian matrix (invalid pair of elements)
      {
         blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0).real( 1 );
         mat(0,2).imag( 4 );
         mat(1,1).real( 2 );
         mat(2,0).imag( 4 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isHermitian( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Hermitian matrix
      {
         blaze::CompressedMatrix<cplx,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0).real(  1 );
         mat(0,2).imag(  4 );
         mat(1,1).real(  2 );
         mat(2,0).imag( -4 );
         mat(2,2).real(  3 );
         mat.insert( 0UL, 1UL, 0 );
         mat.insert( 1UL, 0UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 7UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major symmetric matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isHermitian() (symmetric matrix)";

      // Default symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal symmetric matrix (non-real element)
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).imag( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isHermitian( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric matrix (built-in data type)
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric matrix (complex data type)
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).imag( 4 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isHermitian( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major Hermitian matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isHermitian() (Hermitian matrix)";

      // Default Hermitian matrix (built-in data type)
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric Hermitian matrix (built-in data type)
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Default Hermitian matrix (complex data type)
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric Hermitian matrix (complex data type)
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).real( 4 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // General Hermitian matrix (complex data type)
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).imag( 4 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major lower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isHermitian() (lower matrix)";

      // Default lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,0).imag( 4 );
         mat(1,1).real( 2 );
         mat(2,0).imag( 5 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isHermitian( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major unilower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isHermitian() (unilower matrix)";

      // Default unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(1,0).imag( 4 );
         mat(2,0).imag( 5 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isHermitian( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major strictly lower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isHermitian() (strictly lower matrix)";

      // Default strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(1,0).imag( 4 );
         mat(2,0).imag( 5 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isHermitian( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major upper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isHermitian() (upper matrix)";

      // Default upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).imag( 4 );
         mat(1,1).real( 2 );
         mat(1,2).imag( 5 );
         mat(2,2).real( 1 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isHermitian( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major uniupper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isHermitian() (uniupper matrix)";

      // Default uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,2).imag( 4 );
         mat(1,2).imag( 5 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isHermitian( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major strictly upper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isHermitian() (strictly upper matrix)";

      // Default strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,2).imag( 4 );
         mat(1,2).imag( 5 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isHermitian( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major diagonal matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isHermitian() (diagonal matrix)";

      // Default diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isHermitian( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isHermitian evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c isUniform() function for dense matrices.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c isUniform() function for dense matrices. In case an
// error is detected, a \a std::runtime_error exception is thrown.
*/
void OperationTest::testIsUniform()
{
   //=====================================================================================
   // Row-major general matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniform() (general matrix)";

      // Uniform matrix (0x3)
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 0UL, 3UL );

         checkRows    ( mat, 0UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 0UL );
         checkNonZeros( mat, 0UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniform matrix (3x0)
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 0UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 0UL );
         checkCapacity( mat, 0UL );
         checkNonZeros( mat, 0UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniform matrix (1x3)
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 1UL, 3UL, 3UL );
         mat(0,0) = 5;
         mat(0,1) = 5;
         mat(0,2) = 5;

         checkRows    ( mat, 1UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 3UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniform matrix (3x1)
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 1UL, 3UL );
         mat(0,0) = 5;
         mat(1,0) = 5;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 1UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniform matrix (3x5)
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 5UL, 3UL );
         mat.insert( 0UL, 1UL, 0 );
         mat.insert( 1UL, 2UL, 0 );
         mat.insert( 2UL, 0UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 5UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniform matrix (5x3)
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 5UL, 3UL, 5UL );
         mat.insert( 0UL, 1UL, 0 );
         mat.insert( 1UL, 2UL, 0 );
         mat.insert( 2UL, 0UL, 0 );
         mat.insert( 3UL, 1UL, 0 );
         mat.insert( 4UL, 2UL, 0 );

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );
         checkNonZeros( mat, 3UL, 1UL );
         checkNonZeros( mat, 4UL, 1UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-uniform matrix (3x3, 3 non-zero elements)
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 3UL );
         mat.insert( 0UL, 1UL, 0 );
         mat.insert( 1UL, 0UL, 0 );
         mat.insert( 2UL, 2UL, 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-uniform matrix (3x3, 9 non-zero elements)
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 9UL );
         for( size_t i=0UL; i<3UL; ++i )
            for( size_t j=0UL; j<3UL; ++j )
               mat.insert( i, j, 0UL );
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 9UL );
         checkNonZeros( mat, 9UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 3UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isUniform( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major symmetric matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniform() (symmetric matrix)";

      // Uniform symmetric matrix (0 non-zeros)
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniform symmetric matrix (5 non-zeros)
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat.insert( 0UL, 0UL, 0 );
         mat.insert( 1UL, 0UL, 0 );
         mat.insert( 2UL, 0UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniform symmetric matrix (9 non-zeros)
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         for( size_t i=0UL; i<3UL; ++i )
            for( size_t j=0UL; j<=i; ++j )
               mat(i,j) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 9UL );
         checkNonZeros( mat, 9UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 3UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-uniform symmetric matrix (2 non-zeros)
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,2) = 4;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-uniform symmetric matrix (9 non-zeros)
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         for( size_t i=0UL; i<3UL; ++i )
            for( size_t j=0UL; j<=i; ++j )
               mat(i,j) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 9UL );
         checkNonZeros( mat, 9UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 3UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isUniform( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major Hermitian matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniform() (Hermitian matrix)";

      // Uniform Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-uniform Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,2).imag( 4 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major lower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniform() (lower matrix)";

      // Uniform lower matrix (0 non-zeros)
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniform lower matrix (3 non-zeros)
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat.insert( 0UL, 0UL, 0 );
         mat.insert( 1UL, 0UL, 0 );
         mat.insert( 2UL, 0UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-uniform lower matrix (1 non-zero)
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 1UL );
         checkNonZeros( mat, 1UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major unilower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniform() (unilower matrix)";

      // Non-uniform unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major strictly lower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniform() (strictly lower matrix)";

      // Default strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major upper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniform() (upper matrix)";

      // Uniform upper matrix (0 non-zeros)
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniform upper matrix (3 non-zeros)
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat.insert( 0UL, 2UL, 0 );
         mat.insert( 1UL, 2UL, 0 );
         mat.insert( 2UL, 2UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-uniform upper matrix (1 non-zero)
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 1UL );
         checkNonZeros( mat, 1UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniform( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major uniupper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniform() (uniupper matrix)";

      // Non-uniform uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major strictly upper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniform() (strictly upper matrix)";

      // Default strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniform( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major diagonal matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniform() (diagonal matrix)";

      // Uniform diagonal matrix (0 non-zeros)
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniform diagonal matrix (3 non-zeros)
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat.insert( 0UL, 0UL, 0 );
         mat.insert( 1UL, 1UL, 0 );
         mat.insert( 2UL, 2UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-uniform diagonal matrix (1 non-zero)
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(2,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 1UL );
         checkNonZeros( mat, 1UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major general matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniform() (general matrix)";

      // Uniform matrix (0x3)
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 0UL, 3UL );

         checkRows    ( mat, 0UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 0UL );
         checkNonZeros( mat, 0UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniform matrix (3x0)
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 0UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 0UL );
         checkCapacity( mat, 0UL );
         checkNonZeros( mat, 0UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniform matrix (1x3)
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 1UL, 3UL, 3UL );
         mat(0,0) = 5;
         mat(0,1) = 5;
         mat(0,2) = 5;

         checkRows    ( mat, 1UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniform matrix (3x1)
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 1UL, 3UL );
         mat(0,0) = 5;
         mat(1,0) = 5;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 1UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 3UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniform matrix (3x5)
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 5UL, 5UL );
         mat.insert( 0UL, 0UL, 0 );
         mat.insert( 2UL, 1UL, 0 );
         mat.insert( 1UL, 2UL, 0 );
         mat.insert( 2UL, 3UL, 0 );
         mat.insert( 0UL, 4UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 5UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );
         checkNonZeros( mat, 3UL, 1UL );
         checkNonZeros( mat, 4UL, 1UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniform matrix (5x3)
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 5UL, 3UL, 3UL );
         mat.insert( 1UL, 0UL, 0 );
         mat.insert( 2UL, 1UL, 0 );
         mat.insert( 0UL, 2UL, 0 );

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-uniform matrix (3x3, 3 non-zero elements)
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 3UL );
         mat.insert( 1UL, 0UL, 0 );
         mat.insert( 0UL, 1UL, 0 );
         mat.insert( 2UL, 2UL, 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-uniform matrix (3x3, 9 non-zero elements)
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 9UL );
         for( size_t i=0UL; i<3UL; ++i )
            for( size_t j=0UL; j<3UL; ++j )
               mat.insert( i, j, 0UL );
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 9UL );
         checkNonZeros( mat, 9UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 3UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isUniform( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major symmetric matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniform() (symmetric matrix)";

      // Uniform symmetric matrix (0 non-zeros)
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniform symmetric matrix (5 non-zeros)
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat.insert( 0UL, 0UL, 0 );
         mat.insert( 1UL, 0UL, 0 );
         mat.insert( 2UL, 0UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniform symmetric matrix (9 non-zeros)
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         for( size_t i=0UL; i<3UL; ++i )
            for( size_t j=0UL; j<=i; ++j )
               mat(i,j) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 9UL );
         checkNonZeros( mat, 9UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 3UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-uniform symmetric matrix (2 non-zeros)
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,2) = 4;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-uniform symmetric matrix (9 non-zeros)
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         for( size_t i=0UL; i<3UL; ++i )
            for( size_t j=0UL; j<=i; ++j )
               mat(i,j) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 9UL );
         checkNonZeros( mat, 9UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 3UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isUniform( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major Hermitian matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniform() (Hermitian matrix)";

      // Uniform Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-uniform Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,2).imag( 4 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major lower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniform() (lower matrix)";

      // Uniform lower matrix (0 non-zeros)
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniform lower matrix (3 non-zeros)
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat.insert( 2UL, 0UL, 0 );
         mat.insert( 2UL, 1UL, 0 );
         mat.insert( 2UL, 2UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-uniform lower matrix (1 non-zero)
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 1UL );
         checkNonZeros( mat, 1UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniform( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major unilower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniform() (unilower matrix)";

      // Non-uniform unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major strictly lower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniform() (strictly lower matrix)";

      // Default strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniform( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major upper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniform() (upper matrix)";

      // Uniform upper matrix (0 non-zeros)
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniform upper matrix (3 non-zeros)
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat.insert( 0UL, 0UL, 0 );
         mat.insert( 0UL, 1UL, 0 );
         mat.insert( 0UL, 2UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-uniform upper matrix (1 non-zero)
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 1UL );
         checkNonZeros( mat, 1UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major uniupper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniform() (uniupper matrix)";

      // Non-uniform uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major strictly upper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniform() (strictly upper matrix)";

      // Default strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUniform( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major diagonal matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniform() (diagonal matrix)";

      // Uniform diagonal matrix (0 non-zeros)
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniform diagonal matrix (3 non-zeros)
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat.insert( 0UL, 0UL, 0 );
         mat.insert( 1UL, 1UL, 0 );
         mat.insert( 2UL, 2UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-uniform diagonal matrix (1 non-zero)
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(2,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 1UL );
         checkNonZeros( mat, 1UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniform( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniform evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c isLower() function for sparse matrices.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c isLower() function for sparse matrices. In case an
// error is detected, a \a std::runtime_error exception is thrown.
*/
void OperationTest::testIsLower()
{
   //=====================================================================================
   // Row-major general matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isLower() (general matrix)";

      // Non-square matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 2UL, 3UL );

         checkRows    ( mat, 2UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );

         if( isLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Default initialized matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;
         mat.insert( 1UL, 2UL, 0 );
         mat.insert( 2UL, 0UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-lower triangular matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 6UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,0) = 3;
         mat(1,1) = 4;
         mat(2,2) = 5;
         mat(2,0) = 6;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 6UL );
         checkNonZeros( mat, 6UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower triangular matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(1,0) = 2;
         mat(1,1) = 3;
         mat(2,2) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major symmetric matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isLower() (symmetric matrix)";

      // Default symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major Hermitian matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isLower() (Hermitian matrix)";

      // Default Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).imag( 4 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major lower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isLower() (lower matrix)";

      // Default lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,0) = 4;
         mat(1,1) = 2;
         mat(2,0) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major unilower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isLower() (unilower matrix)";

      // Default unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major strictly lower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isLower() (strictly lower matrix)";

      // Default strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major upper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isLower() (upper matrix)";

      // Default upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(1,2) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major uniupper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isLower() (uniupper matrix)";

      // Default uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major strictly upper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isLower() (strictly upper matrix)";

      // Default strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major diagonal matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isLower() (diagonal matrix)";

      // Default diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major general matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isLower() (general matrix)";

      // Non-square matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 2UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 2UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );

         if( isLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Default initialized matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;
         mat.insert( 1UL, 2UL, 0 );
         mat.insert( 2UL, 0UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-lower triangle matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 6UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,0) = 3;
         mat(1,1) = 4;
         mat(2,2) = 5;
         mat(2,0) = 6;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 6UL );
         checkNonZeros( mat, 6UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower triangular matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(1,0) = 2;
         mat(1,1) = 3;
         mat(2,2) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major symmetric matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isLower() (symmetric matrix)";

      // Default symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major Hermitian matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isLower() (Hermitian matrix)";

      // Default Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).imag( 4 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major lower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isLower() (lower matrix)";

      // Default lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,0) = 4;
         mat(1,1) = 2;
         mat(2,0) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major unilower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isLower() (unilower matrix)";

      // Default unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major strictly lower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isLower() (strictly lower matrix)";

      // Default strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major upper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isLower() (upper matrix)";

      // Default upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(1,2) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major uniupper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isLower() (uniupper matrix)";

      // Default uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major strictly upper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isLower() (strictly upper matrix)";

      // Default strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major diagonal matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isLower() (diagonal matrix)";

      // Default diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c isUniLower() function for sparse matrices.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c isUniLower() function for sparse matrices. In case an
// error is detected, a \a std::runtime_error exception is thrown.
*/
void OperationTest::testIsUniLower()
{
   //=====================================================================================
   // Row-major general matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniLower() (general matrix)";

      // Non-square matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 2UL, 3UL );

         checkRows    ( mat, 2UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Default initialized matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;
         mat.insert( 1UL, 2UL, 0 );
         mat.insert( 2UL, 0UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower unitriangular matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(1,0) = 2;
         mat(1,1) = 1;
         mat(2,2) = 1;
         mat(2,0) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUniLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower triangular matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(1,0) = 2;
         mat(1,1) = 3;
         mat(2,2) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-lower unitriangular matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 6UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,0) = 3;
         mat(1,1) = 1;
         mat(2,2) = 1;
         mat(2,0) = 4;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 6UL );
         checkNonZeros( mat, 6UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major symmetric matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniLower() (symmetric matrix)";

      // Default symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major Hermitian matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniLower() (Hermitian matrix)";

      // Default Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 1 );
         mat(2,2).real( 1 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Hermitian matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).imag( 2 );
         mat(1,1).real( 1 );
         mat(2,2).real( 1 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major lower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniLower() (lower matrix)";

      // Default lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower unitriangular matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,0) = 2;
         mat(1,1) = 1;
         mat(2,0) = 3;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUniLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,0) = 4;
         mat(1,1) = 2;
         mat(2,0) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major unilower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniLower() (unilower matrix)";

      // Default unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(1,0) = 2;
         mat(2,0) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUniLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major strictly lower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniLower() (strictly lower matrix)";

      // Default strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major upper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniLower() (upper matrix)";

      // Default upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper unitriangular matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,1) = 1;
         mat(1,2) = 3;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(1,2) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major uniupper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniLower() (uniupper matrix)";

      // Default uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,2) = 2;
         mat(1,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major strictly upper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniLower() (strictly upper matrix)";

      // Default strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major diagonal matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniLower() (diagonal matrix)";

      // Default diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major general matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniLower() (general matrix)";

      // Non-square matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 2UL, 3UL );

         checkRows    ( mat, 2UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Default initialized matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;
         mat.insert( 1UL, 2UL, 0 );
         mat.insert( 2UL, 0UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower unitriangular matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(1,0) = 2;
         mat(1,1) = 1;
         mat(2,2) = 1;
         mat(2,0) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower triangular matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(1,0) = 2;
         mat(1,1) = 3;
         mat(2,2) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-lower unitriangular matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 6UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,0) = 3;
         mat(1,1) = 1;
         mat(2,2) = 1;
         mat(2,0) = 4;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 6UL );
         checkNonZeros( mat, 6UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major symmetric matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniLower() (symmetric matrix)";

      // Default symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major Hermitian matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniLower() (Hermitian matrix)";

      // Default Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 1 );
         mat(2,2).real( 1 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Hermitian matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).imag( 2 );
         mat(1,1).real( 1 );
         mat(2,2).real( 1 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major lower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniLower() (lower matrix)";

      // Default lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower unitriangular matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,0) = 2;
         mat(1,1) = 1;
         mat(2,0) = 3;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,0) = 4;
         mat(1,1) = 2;
         mat(2,0) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major unilower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniLower() (unilower matrix)";

      // Default unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(1,0) = 2;
         mat(2,0) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major strictly lower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniLower() (strictly lower matrix)";

      // Default strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major upper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniLower() (upper matrix)";

      // Default upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper unitriangular matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,1) = 1;
         mat(1,2) = 3;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(1,2) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major uniupper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniLower() (uniupper matrix)";

      // Default uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,2) = 2;
         mat(1,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major strictly upper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniLower() (strictly upper matrix)";

      // Default strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major diagonal matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniLower() (diagonal matrix)";

      // Default diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c isStrictlyLower() function for sparse matrices.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c isStrictlyLower() function for sparse matrices. In
// case an error is detected, a \a std::runtime_error exception is thrown.
*/
void OperationTest::testIsStrictlyLower()
{
   //=====================================================================================
   // Row-major general matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isStrictlyLower() (general matrix)";

      // Non-square matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 2UL, 3UL );

         checkRows    ( mat, 2UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Default initialized matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;
         mat.insert( 1UL, 2UL, 0 );
         mat.insert( 2UL, 0UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower triangular matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 2UL );
         mat(1,0) = 2;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower triangular matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(1,0) = 2;
         mat(1,1) = 3;
         mat(2,2) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-strictly lower triangular matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 3UL );
         mat(0,2) = 2;
         mat(1,0) = 3;
         mat(2,0) = 4;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major symmetric matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isStrictlyLower() (symmetric matrix)";

      // Default symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major Hermitian matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isStrictlyLower() (Hermitian matrix)";

      // Default Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).imag( 4 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major lower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isStrictlyLower() (lower matrix)";

      // Default lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower triangular matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,0) = 4;
         mat(1,1) = 2;
         mat(2,0) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major unilower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isStrictlyLower() (unilower matrix)";

      // Default unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Unilower triangular matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major strictly lower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isStrictlyLower() (strictly lower matrix)";

      // Default strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower triangular matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major upper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isStrictlyLower() (upper matrix)";

      // Default upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper triangular matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(1,2) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major uniupper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isStrictlyLower() (uniupper matrix)";

      // Default uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniupper triangular matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major strictly upper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isStrictlyLower() (strictly upper matrix)";

      // Default strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper triangular matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major diagonal matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isStrictlyLower() (diagonal matrix)";

      // Default diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major general matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isStrictlyLower() (general matrix)";

      // Non-square matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 2UL, 3UL );

         checkRows    ( mat, 2UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Default initialized matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;
         mat.insert( 1UL, 2UL, 0 );
         mat.insert( 2UL, 0UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower triangular matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 2UL );
         mat(1,0) = 2;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower triangular matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(1,0) = 2;
         mat(1,1) = 3;
         mat(2,2) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-strictly lower triangular matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 3UL );
         mat(0,2) = 2;
         mat(1,0) = 3;
         mat(2,0) = 4;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major symmetric matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isStrictlyLower() (symmetric matrix)";

      // Default symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major Hermitian matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isStrictlyLower() (Hermitian matrix)";

      // Default Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).imag( 4 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major lower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isStrictlyLower() (lower matrix)";

      // Default lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower triangular matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,0) = 4;
         mat(1,1) = 2;
         mat(2,0) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major unilower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isStrictlyLower() (unilower matrix)";

      // Default unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Unilower triangular matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major strictly lower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isStrictlyLower() (strictly lower matrix)";

      // Default strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower triangular matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major upper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isStrictlyLower() (upper matrix)";

      // Default upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper triangular matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(1,2) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major uniupper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isStrictlyLower() (uniupper matrix)";

      // Default uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniupper triangular matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major strictly upper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isStrictlyLower() (strictly upper matrix)";

      // Default strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper triangular matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major diagonal matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isStrictlyLower() (diagonal matrix)";

      // Default diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyLower( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyLower( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyLower evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c isUpper() function for sparse matrices.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c isUpper() function for sparse matrices. In case an
// error is detected, a \a std::runtime_error exception is thrown.
*/
void OperationTest::testIsUpper()
{
   //=====================================================================================
   // Row-major general matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUpper() (general matrix)";

      // Non-square matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 2UL, 3UL );

         checkRows    ( mat, 2UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );

         if( isUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Default initialized matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;
         mat.insert( 1UL, 2UL, 0 );
         mat.insert( 2UL, 0UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-upper triangle matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 6UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,1) = 3;
         mat(1,2) = 4;
         mat(2,0) = 5;
         mat(2,2) = 6;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 6UL );
         checkNonZeros( mat, 6UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper triangular matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,1) = 3;
         mat(1,2) = 4;
         mat(2,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major symmetric matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUpper() (symmetric matrix)";

      // Default symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major Hermitian matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUpper() (Hermitian matrix)";

      // Default Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).imag( 4 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major lower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUpper() (lower matrix)";

      // Default lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,0) = 4;
         mat(1,1) = 2;
         mat(2,0) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major unilower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUpper() (unilower matrix)";

      // Default unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major strictly lower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUpper() (strictly lower matrix)";

      // Default strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major upper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUpper() (upper matrix)";

      // Default upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(1,2) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major uniupper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUpper() (uniupper matrix)";

      // Default uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major strictly upper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUpper() (strictly upper matrix)";

      // Default strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major diagonal matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUpper() (diagonal matrix)";

      // Default diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major general matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUpper() (general matrix)";

      // Non-square matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 2UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 2UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );

         if( isUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Default initialized matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;
         mat.insert( 1UL, 2UL, 0 );
         mat.insert( 2UL, 0UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-upper triangle matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 6UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,1) = 3;
         mat(1,2) = 4;
         mat(2,0) = 5;
         mat(2,2) = 6;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 6UL );
         checkNonZeros( mat, 6UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper triangular matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,1) = 3;
         mat(1,2) = 4;
         mat(2,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major symmetric matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUpper() (symmetric matrix)";

      // Default symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major Hermitian matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUpper() (Hermitian matrix)";

      // Default Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).imag( 4 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major lower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUpper() (lower matrix)";

      // Default lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,0) = 4;
         mat(1,1) = 2;
         mat(2,0) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major unilower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUpper() (unilower matrix)";

      // Default unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major strictly lower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUpper() (strictly lower matrix)";

      // Default strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major upper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUpper() (upper matrix)";

      // Default upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(1,2) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major uniupper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUpper() (uniupper matrix)";

      // Default uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major strictly upper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUpper() (strictly upper matrix)";

      // Default strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major diagonal matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUpper() (diagonal matrix)";

      // Default diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c isUniUpper() function for sparse matrices.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c isUniUpper() function for sparse matrices. In case an
// error is detected, a \a std::runtime_error exception is thrown.
*/
void OperationTest::testIsUniUpper()
{
   //=====================================================================================
   // Row-major general matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniUpper() (general matrix)";

      // Non-square matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 2UL, 3UL );

         checkRows    ( mat, 2UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Default initialized matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;
         mat.insert( 1UL, 2UL, 0 );
         mat.insert( 2UL, 0UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper unitriangular matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,1) = 1;
         mat(1,2) = 3;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper triangular matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,1) = 3;
         mat(1,2) = 4;
         mat(2,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-upper triangular matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 6UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,1) = 1;
         mat(1,2) = 3;
         mat(2,0) = 4;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 6UL );
         checkNonZeros( mat, 6UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major symmetric matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniUpper() (symmetric matrix)";

      // Default symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major Hermitian matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniUpper() (Hermitian matrix)";

      // Default Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 1 );
         mat(2,2).real( 1 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).imag( 2 );
         mat(1,1).real( 1 );
         mat(2,2).real( 1 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major lower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniUpper() (lower matrix)";

      // Default lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower unitriangular matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,0) = 2;
         mat(1,1) = 1;
         mat(2,0) = 3;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower triangular matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,0) = 4;
         mat(1,1) = 2;
         mat(2,0) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major unilower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniUpper() (unilower matrix)";

      // Default unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(1,0) = 2;
         mat(2,0) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major strictly lower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniUpper() (strictly lower matrix)";

      // Default strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major upper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniUpper() (upper matrix)";

      // Default upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper unitriangular matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,1) = 1;
         mat(1,2) = 3;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper triangular matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(1,2) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major uniupper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniUpper() (uniupper matrix)";

      // Default uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,2) = 2;
         mat(1,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major strictly upper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniUpper() (strictly upper matrix)";

      // Default strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major diagonal matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isUniUpper() (diagonal matrix)";

      // Default diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major general matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniUpper() (general matrix)";

      // Non-square matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 2UL, 3UL );

         checkRows    ( mat, 2UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Default initialized matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;
         mat.insert( 1UL, 2UL, 0 );
         mat.insert( 2UL, 0UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper unitriangular matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,1) = 1;
         mat(1,2) = 3;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isUniUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper triangular matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,1) = 3;
         mat(1,2) = 4;
         mat(2,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-upper triangular matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 6UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,1) = 1;
         mat(1,2) = 3;
         mat(2,0) = 4;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 6UL );
         checkNonZeros( mat, 6UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major symmetric matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniUpper() (symmetric matrix)";

      // Default symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major Hermitian matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniUpper() (Hermitian matrix)";

      // Default Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 1 );
         mat(2,2).real( 1 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).imag( 2 );
         mat(1,1).real( 1 );
         mat(2,2).real( 1 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major lower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniUpper() (lower matrix)";

      // Default lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower unitriangular matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,0) = 2;
         mat(1,1) = 1;
         mat(2,0) = 3;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower triangular matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,0) = 4;
         mat(1,1) = 2;
         mat(2,0) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major unilower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniUpper() (unilower matrix)";

      // Default unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major strictly lower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniUpper() (strictly lower matrix)";

      // Default strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major upper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniUpper() (upper matrix)";

      // Default upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper unitriangular matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,1) = 1;
         mat(1,2) = 3;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isUniUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper triangular matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(1,2) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major uniupper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniUpper() (uniupper matrix)";

      // Default uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isUniUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major strictly upper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniUpper() (strictly upper matrix)";

      // Default strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major diagonal matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isUniUpper() (diagonal matrix)";

      // Default diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isUniUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isUniUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c isStrictlyUpper() function for sparse matrices.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c isStrictlyUpper() function for sparse matrices. In
// case an error is detected, a \a std::runtime_error exception is thrown.
*/
void OperationTest::testIsStrictlyUpper()
{
   //=====================================================================================
   // Row-major general matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isStrictlyUpper() (general matrix)";

      // Non-square matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 2UL, 3UL );

         checkRows    ( mat, 2UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Default initialized matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;
         mat.insert( 1UL, 2UL, 0 );
         mat.insert( 2UL, 0UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper triangular matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 2UL );
         mat(0,2) = 2;
         mat(1,2) = 4;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper triangular matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,1) = 3;
         mat(1,2) = 4;
         mat(2,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-strictly upper triangular matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 3UL );
         mat(0,2) = 2;
         mat(1,2) = 3;
         mat(2,0) = 4;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major symmetric matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isStrictlyUpper() (symmetric matrix)";

      // Default symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major Hermitian matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isStrictlyUpper() (Hermitian matrix)";

      // Default Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).imag( 4 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major lower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isStrictlyUpper() (lower matrix)";

      // Default lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower triangular matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower triangular matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,0) = 4;
         mat(1,1) = 2;
         mat(2,0) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major unilower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isStrictlyUpper() (unilower matrix)";

      // Default unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major strictly lower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isStrictlyUpper() (strictly lower matrix)";

      // Default strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major upper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isStrictlyUpper() (upper matrix)";

      // Default upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper triangular matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper triangular matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(1,2) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major uniupper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isStrictlyUpper() (uniupper matrix)";

      // Default uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major strictly upper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isStrictlyUpper() (strictly upper matrix)";

      // Default strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major diagonal matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isStrictlyUpper() (diagonal matrix)";

      // Default diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major general matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isStrictlyUpper() (general matrix)";

      // Non-square matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 2UL, 3UL );

         checkRows    ( mat, 2UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Default initialized matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;
         mat.insert( 1UL, 2UL, 0 );
         mat.insert( 2UL, 0UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper triangular matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 2UL );
         mat(0,2) = 2;
         mat(1,2) = 4;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isStrictlyUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper triangular matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,1) = 3;
         mat(1,2) = 4;
         mat(2,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Non-strictly upper triangular matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 3UL );
         mat(0,2) = 2;
         mat(1,2) = 3;
         mat(2,0) = 4;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major symmetric matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isStrictlyUpper() (symmetric matrix)";

      // Default symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major Hermitian matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isStrictlyUpper() (Hermitian matrix)";

      // Default Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).imag( 4 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major lower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isStrictlyUpper() (lower matrix)";

      // Default lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower triangular matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower triangular matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,0) = 4;
         mat(1,1) = 2;
         mat(2,0) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major unilower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isStrictlyUpper() (unilower matrix)";

      // Default unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major strictly lower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isStrictlyUpper() (strictly lower matrix)";

      // Default strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major upper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isStrictlyUpper() (upper matrix)";

      // Default upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper triangular matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isStrictlyUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper triangular matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(1,2) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major uniupper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isStrictlyUpper() (uniupper matrix)";

      // Default uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major strictly upper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isStrictlyUpper() (strictly upper matrix)";

      // Default strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isStrictlyUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major diagonal matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isStrictlyUpper() (diagonal matrix)";

      // Default diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isStrictlyUpper( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isStrictlyUpper( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isStrictlyUpper evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c isDiagonal() function for sparse matrices.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c isDiagonal() function for sparse matrices. In case
// an error is detected, a \a std::runtime_error exception is thrown.
*/
void OperationTest::testIsDiagonal()
{
   //=====================================================================================
   // Row-major general matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isDiagonal() (general matrix)";

      // Non-square matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 2UL, 3UL );

         checkRows    ( mat, 2UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );

         if( isDiagonal( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Default initialized matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;
         mat.insert( 1UL, 2UL, 0 );
         mat.insert( 2UL, 0UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 4UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,0) = 4;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 4UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isDiagonal( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 4UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 4UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isDiagonal( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major symmetric matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isDiagonal() (symmetric matrix)";

      // Default symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isDiagonal( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major Hermitian matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isDiagonal() (Hermitian matrix)";

      // Default Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).imag( 4 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isDiagonal( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major lower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isDiagonal() (lower matrix)";

      // Default lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,0) = 4;
         mat(1,1) = 2;
         mat(2,0) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isDiagonal( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major unilower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isDiagonal() (unilower matrix)";

      // Default unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isDiagonal( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major strictly lower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isDiagonal() (strictly lower matrix)";

      // Default strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isDiagonal( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major upper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isDiagonal() (upper matrix)";

      // Default upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(1,2) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isDiagonal( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major uniupper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isDiagonal() (uniupper matrix)";

      // Default uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isDiagonal( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major strictly upper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isDiagonal() (strictly upper matrix)";

      // Default strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isDiagonal( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major diagonal matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isDiagonal() (diagonal matrix)";

      // Default diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major general matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isDiagonal() (general matrix)";

      // Non-square matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 2UL, 3UL );

         checkRows    ( mat, 2UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isDiagonal( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Default initialized matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;
         mat.insert( 1UL, 2UL, 0 );
         mat.insert( 2UL, 0UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 4UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,0) = 4;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 4UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isDiagonal( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 4UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 4UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isDiagonal( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major symmetric matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isDiagonal() (symmetric matrix)";

      // Default symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isDiagonal( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major Hermitian matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isDiagonal() (Hermitian matrix)";

      // Default Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).imag( 4 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isDiagonal( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major lower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isDiagonal() (lower matrix)";

      // Default lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,0) = 4;
         mat(1,1) = 2;
         mat(2,0) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isDiagonal( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major unilower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isDiagonal() (unilower matrix)";

      // Default unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isDiagonal( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major strictly lower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isDiagonal() (strictly lower matrix)";

      // Default strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isDiagonal( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major upper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isDiagonal() (upper matrix)";

      // Default upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(1,2) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isDiagonal( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major uniupper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isDiagonal() (uniupper matrix)";

      // Default uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isDiagonal( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major strictly upper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isDiagonal() (strictly upper matrix)";

      // Default strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isDiagonal( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major diagonal matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isDiagonal() (diagonal matrix)";

      // Default diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isDiagonal( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDiagonal evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c isIdentity() function for sparse matrices.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c isIdentity() function for sparse matrices. In case
// an error is detected, a \a std::runtime_error exception is thrown.
*/
void OperationTest::testIsIdentity()
{
   //=====================================================================================
   // Row-major general matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isIdentity() (general matrix)";

      // Non-square matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 2UL, 3UL );

         checkRows    ( mat, 2UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Default initialized matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;
         mat.insert( 1UL, 2UL, 0 );
         mat.insert( 2UL, 0UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isIdentity( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Incomplete identity matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 2UL );
         mat(0,0) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 4UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,0) = 2;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 4UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 4UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 4UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major symmetric matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isIdentity() (symmetric matrix)";

      // Default symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major Hermitian matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isIdentity() (Hermitian matrix)";

      // Default Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 1 );
         mat(2,2).real( 1 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::rowMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).imag( 4 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major lower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isIdentity() (lower matrix)";

      // Default lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,0) = 4;
         mat(1,1) = 2;
         mat(2,0) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major unilower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isIdentity() (unilower matrix)";

      // Default unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major strictly lower matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isIdentity() (strictly lower matrix)";

      // Default strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major upper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isIdentity() (upper matrix)";

      // Default upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(1,2) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major uniupper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isIdentity() (uniupper matrix)";

      // Default uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 2UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major strictly upper matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isIdentity() (strictly upper matrix)";

      // Default strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major diagonal matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isIdentity() (diagonal matrix)";

      // Default diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::rowMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major general matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isIdentity()";

      // Non-square matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 2UL, 3UL );

         checkRows    ( mat, 2UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Default initialized matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;
         mat.insert( 1UL, 2UL, 0 );
         mat.insert( 2UL, 0UL, 0 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isIdentity( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Incomplete identity matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 2UL );
         mat(0,0) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 4UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,0) = 2;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 4UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 4UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 4UL );
         checkNonZeros( mat, 4UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major symmetric matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isIdentity() (symmetric matrix)";

      // Default symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Symmetric matrix
      {
         blaze::SymmetricMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major Hermitian matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isIdentity() (Hermitian matrix)";

      // Default Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 1 );
         mat(2,2).real( 1 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Hermitian matrix
      {
         blaze::HermitianMatrix< blaze::CompressedMatrix<cplx,blaze::columnMajor> > mat( 3UL );
         mat(0,0).real( 1 );
         mat(0,2).imag( 4 );
         mat(1,1).real( 2 );
         mat(2,2).real( 3 );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major lower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isIdentity() (lower matrix)";

      // Default lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Lower matrix
      {
         blaze::LowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,0) = 4;
         mat(1,1) = 2;
         mat(2,0) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major unilower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isIdentity() (unilower matrix)";

      // Default unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Unilower matrix
      {
         blaze::UniLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 3UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major strictly lower matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isIdentity() (strictly lower matrix)";

      // Default strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly lower matrix
      {
         blaze::StrictlyLowerMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(1,0) = 4;
         mat(2,0) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 2UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major upper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isIdentity() (upper matrix)";

      // Default upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Upper matrix
      {
         blaze::UpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(0,2) = 4;
         mat(1,1) = 2;
         mat(1,2) = 5;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major uniupper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isIdentity() (uniupper matrix)";

      // Default uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Uniupper matrix
      {
         blaze::UniUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 5UL );
         checkNonZeros( mat, 5UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 3UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major strictly upper matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isIdentity() (strictly upper matrix)";

      // Default strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Strictly upper matrix
      {
         blaze::StrictlyUpperMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,2) = 4;
         mat(1,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 2UL );
         checkNonZeros( mat, 2UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 2UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major diagonal matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isIdentity() (diagonal matrix)";

      // Default diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 0UL );
         checkNonZeros( mat, 0UL, 0UL );
         checkNonZeros( mat, 1UL, 0UL );
         checkNonZeros( mat, 2UL, 0UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Identity diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 1;
         mat(2,2) = 1;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Diagonal matrix
      {
         blaze::DiagonalMatrix< blaze::CompressedMatrix<int,blaze::columnMajor> > mat( 3UL );
         mat(0,0) = 1;
         mat(1,1) = 2;
         mat(2,2) = 3;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkCapacity( mat, 3UL );
         checkNonZeros( mat, 3UL );
         checkNonZeros( mat, 0UL, 1UL );
         checkNonZeros( mat, 1UL, 1UL );
         checkNonZeros( mat, 2UL, 1UL );

         if( isIdentity( mat ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isIdentity evaluation\n"
                << " Details:\n"
                << "   Matrix:\n" << mat << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c min() function for sparse matrices.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c min() function for sparse matrices template. In case an
// error is detected, a \a std::runtime_error exception is thrown.
*/
void OperationTest::testMinimum()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major min()";

      // Attempt to find the minimum at the beginning in a fully filled matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 2UL, 5UL );
         mat(0,0) = -1;
         mat(0,1) =  2;
         mat(1,0) =  3;
         mat(1,1) =  4;
         mat(2,0) =  5;
         mat(2,1) =  6;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 2UL );
         checkNonZeros( mat, 6UL );

         const int minimum = min( mat );

         if( minimum != -1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: First computation failed\n"
                << " Details:\n"
                << "   Result: " << minimum << "\n"
                << "   Expected result: -1\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Attempt to find the minimum at the end in a fully filled matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 2UL, 3UL, 5UL );
         mat(0,0) =  1;
         mat(0,1) =  2;
         mat(0,2) =  3;
         mat(1,0) =  4;
         mat(1,1) =  5;
         mat(1,2) = -6;

         checkRows    ( mat, 2UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 6UL );

         const int minimum = min( mat );

         if( minimum != -6 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Second computation failed\n"
                << " Details:\n"
                << "   Result: " << minimum << "\n"
                << "   Expected result: -6\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Attempt to find the minimum at the beginning in a partially filled matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 5UL, 3UL, 5UL );
         mat(0,0) = -1;
         mat(0,2) =  2;
         mat(2,1) =  3;
         mat(4,0) =  4;
         mat(4,2) =  5;

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 5UL );

         const int minimum = min( mat );

         if( minimum != -1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Third computation failed\n"
                << " Details:\n"
                << "   Result: " << minimum << "\n"
                << "   Expected result: -1\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Attempt to find the minimum at the end in a partially filled matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 5UL, 5UL );
         mat(0,0) =  1;
         mat(0,4) =  2;
         mat(1,2) =  3;
         mat(2,0) =  4;
         mat(2,4) = -5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 5UL );
         checkNonZeros( mat, 5UL );

         const int minimum = min( mat );

         if( minimum != -5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Fourth computation failed\n"
                << " Details:\n"
                << "   Result: " << minimum << "\n"
                << "   Expected result: -5\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Attempt to detect 0 as the minimum value
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,1) = 3;
         mat(2,0) = 4;
         mat(2,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 5UL );

         const int minimum = min( mat );

         if( minimum != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Fifth computation failed\n"
                << " Details:\n"
                << "   Result: " << minimum << "\n"
                << "   Expected result: 0\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major min()";

      // Attempt to find the minimum at the beginning in a partially filled matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 5UL, 3UL, 5UL );
         mat(0,0) = -1;
         mat(0,2) =  2;
         mat(2,1) =  3;
         mat(4,0) =  4;
         mat(4,2) =  5;

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 5UL );

         const int minimum = min( mat );

         if( minimum != -1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: First computation failed\n"
                << " Details:\n"
                << "   Result: " << minimum << "\n"
                << "   Expected result: -1\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Attempt to find the minimum at the end in a partially filled matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 5UL, 5UL );
         mat(0,0) =  1;
         mat(0,4) =  2;
         mat(1,2) =  3;
         mat(2,0) =  4;
         mat(2,4) = -5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 5UL );
         checkNonZeros( mat, 5UL );

         const int minimum = min( mat );

         if( minimum != -5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Second computation failed\n"
                << " Details:\n"
                << "   Result: " << minimum << "\n"
                << "   Expected result: -5\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Attempt to find the minimum at the beginning in a partially filled matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 5UL, 3UL, 5UL );
         mat(0,0) = -1;
         mat(0,2) =  2;
         mat(2,1) =  3;
         mat(4,0) =  4;
         mat(4,2) =  5;

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 5UL );

         const int minimum = min( mat );

         if( minimum != -1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Third computation failed\n"
                << " Details:\n"
                << "   Result: " << minimum << "\n"
                << "   Expected result: -1\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Attempt to find the minimum at the end in a partially filled matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 5UL, 5UL );
         mat(0,0) =  1;
         mat(0,4) =  2;
         mat(1,2) =  3;
         mat(2,0) =  4;
         mat(2,4) = -5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 5UL );
         checkNonZeros( mat, 5UL );

         const int minimum = min( mat );

         if( minimum != -5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Fourth computation failed\n"
                << " Details:\n"
                << "   Result: " << minimum << "\n"
                << "   Expected result: -5\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Attempt to detect 0 as the minimum value
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = 1;
         mat(0,2) = 2;
         mat(1,1) = 3;
         mat(2,0) = 4;
         mat(2,2) = 5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 5UL );

         const int minimum = min( mat );

         if( minimum != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Fifth computation failed\n"
                << " Details:\n"
                << "   Result: " << minimum << "\n"
                << "   Expected result: 0\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c max() function for sparse matrices.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c max() function for sparse matrices template. In case an
// error is detected, a \a std::runtime_error exception is thrown.
*/
void OperationTest::testMaximum()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major max()";

      // Attempt to find the maximum at the beginning in a fully filled matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 2UL, 5UL );
         mat(0,0) =  1;
         mat(0,1) = -2;
         mat(1,0) = -3;
         mat(1,1) = -4;
         mat(2,0) = -5;
         mat(2,1) = -6;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 2UL );
         checkNonZeros( mat, 6UL );

         const int maximum = max( mat );

         if( maximum != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: First computation failed\n"
                << " Details:\n"
                << "   Result: " << maximum << "\n"
                << "   Expected result: 1\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Attempt to find the maximum at the end in a fully filled matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 2UL, 3UL, 5UL );
         mat(0,0) = -1;
         mat(0,1) = -2;
         mat(0,2) = -3;
         mat(1,0) = -4;
         mat(1,1) = -5;
         mat(1,2) =  6;

         checkRows    ( mat, 2UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 6UL );

         const int maximum = max( mat );

         if( maximum != 6 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Second computation failed\n"
                << " Details:\n"
                << "   Result: " << maximum << "\n"
                << "   Expected result: 6\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Attempt to find the maximum at the beginning in a partially filled matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 5UL, 3UL, 5UL );
         mat(0,0) =  1;
         mat(0,2) = -2;
         mat(2,1) = -3;
         mat(4,0) = -4;
         mat(4,2) = -5;

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 5UL );

         const int maximum = max( mat );

         if( maximum != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Third computation failed\n"
                << " Details:\n"
                << "   Result: " << maximum << "\n"
                << "   Expected result: 1\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Attempt to find the maximum at the end in a partially filled matrix
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 5UL, 5UL );
         mat(0,0) = -1;
         mat(0,4) = -2;
         mat(1,2) = -3;
         mat(2,0) = -4;
         mat(2,4) =  5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 5UL );
         checkNonZeros( mat, 5UL );

         const int maximum = max( mat );

         if( maximum != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Fourth computation failed\n"
                << " Details:\n"
                << "   Result: " << maximum << "\n"
                << "   Expected result: 5\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Attempt to detect 0 as the maximum value
      {
         blaze::CompressedMatrix<int,blaze::rowMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = -1;
         mat(0,2) = -2;
         mat(1,1) = -3;
         mat(2,0) = -4;
         mat(2,2) = -5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 5UL );

         const int maximum = max( mat );

         if( maximum != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Fifth computation failed\n"
                << " Details:\n"
                << "   Result: " << maximum << "\n"
                << "   Expected result: 0\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major max()";

      // Attempt to find the maximum at the beginning in a fully filled matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 2UL, 5UL );
         mat(0,0) =  1;
         mat(0,1) = -2;
         mat(1,0) = -3;
         mat(1,1) = -4;
         mat(2,0) = -5;
         mat(2,1) = -6;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 2UL );
         checkNonZeros( mat, 6UL );

         const int maximum = max( mat );

         if( maximum != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: First computation failed\n"
                << " Details:\n"
                << "   Result: " << maximum << "\n"
                << "   Expected result: 1\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Attempt to find the maximum at the end in a fully filled matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 2UL, 3UL, 5UL );
         mat(0,0) = -1;
         mat(0,1) = -2;
         mat(0,2) = -3;
         mat(1,0) = -4;
         mat(1,1) = -5;
         mat(1,2) =  6;

         checkRows    ( mat, 2UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 6UL );

         const int maximum = max( mat );

         if( maximum != 6 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Second computation failed\n"
                << " Details:\n"
                << "   Result: " << maximum << "\n"
                << "   Expected result: 6\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Attempt to find the maximum at the beginning in a partially filled matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 5UL, 3UL, 5UL );
         mat(0,0) =  1;
         mat(0,2) = -2;
         mat(2,1) = -3;
         mat(4,0) = -4;
         mat(4,2) = -5;

         checkRows    ( mat, 5UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 5UL );

         const int maximum = max( mat );

         if( maximum != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Third computation failed\n"
                << " Details:\n"
                << "   Result: " << maximum << "\n"
                << "   Expected result: 1\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Attempt to find the maximum at the end in a partially filled matrix
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 5UL, 5UL );
         mat(0,0) = -1;
         mat(0,4) = -2;
         mat(1,2) = -3;
         mat(2,0) = -4;
         mat(2,4) =  5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 5UL );
         checkNonZeros( mat, 5UL );

         const int maximum = max( mat );

         if( maximum != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Fourth computation failed\n"
                << " Details:\n"
                << "   Result: " << maximum << "\n"
                << "   Expected result: 5\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Attempt to detect 0 as the maximum value
      {
         blaze::CompressedMatrix<int,blaze::columnMajor> mat( 3UL, 3UL, 5UL );
         mat(0,0) = -1;
         mat(0,2) = -2;
         mat(1,1) = -3;
         mat(2,0) = -4;
         mat(2,2) = -5;

         checkRows    ( mat, 3UL );
         checkColumns ( mat, 3UL );
         checkNonZeros( mat, 5UL );

         const int maximum = max( mat );

         if( maximum != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Fifth computation failed\n"
                << " Details:\n"
                << "   Result: " << maximum << "\n"
                << "   Expected result: 0\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************

} // namespace sparsematrix

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
   std::cout << "   Running SparseMatrix operation test..." << std::endl;

   try
   {
      RUN_SPARSEMATRIX_OPERATION_TEST;
   }
   catch( std::exception& ex ) {
      std::cerr << "\n\n ERROR DETECTED during SparseMatrix operation test:\n"
                << ex.what() << "\n";
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
}
//*************************************************************************************************
