#include "pch.h"
#include "CppUnitTest.h"
#include "../pr_07_2_rec/pr_07_2_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
        TEST_METHOD(TestCreateRows)
        {
            const int K = 4; 
            const int N = 3; 

            int** a = new int* [K];
            for (int i = 0; i < K; i++) {
                a[i] = new int[N];
            }

            int Low = 1, High = 5;
            CreateRows(a, K, N, Low, High, 0);

            for (int i = 0; i < K; i++) {
                for (int j = 0; j < N; j++) {
                    Assert::IsTrue(a[i][j] >= Low && a[i][j] <= High);
                }
            }

            for (int i = 0; i < K; i++) {
                delete[] a[i];
            }
            delete[] a;
        }


        TEST_METHOD(TestSearchMaxInEvenRow)
        {
            const int N = 3; 
            int** a = new int* [2]; 
            a[0] = new int[N] {1, 2, 3};
            a[1] = new int[N] {4, 5, 6}; 

            int maxInRow = a[0][0];
            SearchMaxInEvenRow(a, N, 0, 1, maxInRow); 

            Assert::AreEqual(3, maxInRow);

            delete[] a[0];
            delete[] a[1];
            delete[] a;
        }

        TEST_METHOD(TestSearchMinOfMaxInEvenRows)
        {
            const int K = 4; 
            const int N = 3; 

            int** a = new int* [K];
            for (int i = 0; i < K; i++) {
                a[i] = new int[N];
            }

            a[0][0] = 5; a[0][1] = 6; a[0][2] = 7;
            a[1][0] = 10; a[1][1] = 11; a[1][2] = 12; 
            a[2][0] = 2; a[2][1] = 4; a[2][2] = 6;
            a[3][0] = 3; a[3][1] = 1; a[3][2] = 0;

            int minOfMax = 10; 
            SearchMinOfMaxInEvenRows(a, K, N, 0, minOfMax);

            Assert::AreEqual(6, minOfMax);

            for (int i = 0; i < K; i++) {
                delete[] a[i];
            }
            delete[] a;
        }
	};
}
