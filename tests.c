#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "CUnit.h"
//#include "Automated.h"
#include "Basic.h"
#include "program.h"

void addTest(float a, float b, float exp);
void subTest(float a, float b, float exp);
void multTest(float a, float b, float exp);
void divTest(float a, float b, float exp);
void modTest(float a, float b, float exp);
void num_intTest(float a, float b, float exp);
void num_diffTest(float a, float b, float exp);

void test01(void) { addTest(0.0,0.0,0.0);  }
void test02(void) { addTest(1,1,2.0);  }
void test03(void) { addTest(0.0001,0.0,0.0001);  }
void test04(void) { addTest(10001.0000011,01109.0000090,11110.0000101);  }
void test05(void) { addTest(100.01,1,101.01);  }

void test11(void) { subTest(0.0,0.0,0.0);  }
void test12(void) { subTest(1,1,0.0);  }
void test13(void) { subTest(0.0001,0.0,0.0001);  }
void test14(void) { subTest(10001.0000011,00010.0000001,09980.0000011);  }
void test15(void) { subTest(100.01,1,99.01);  }

void test21(void) { multTest(0.0,0.0,0.0);  }
void test22(void) { multTest(1,1,1.0);  }
void test23(void) { multTest(0.0001,0.0,0.0);  }
void test24(void) { multTest(1.1,100,110.0);  }
void test25(void) { multTest(0.25,5,1.25);  }

void test31(void) { divTest(0.0,0.0,0.0);  }
void test32(void) { divTest(1,1,1.0);  }
void test33(void) { divTest(10.0,2.0,5.0);  }
void test34(void) { divTest(10,100,0.1);  }
void test35(void) { divTest(10.0,0.1,100.0);  }

void test41(void) { modTest(0.0,0.0,0.0);  }
void test42(void) { modTest(1,1,0.0);  }
void test43(void) { modTest(20.0,2.0,0.0);  }
void test44(void) { modTest(5.0,4.0,1.0);  }
void test45(void) { modTest(20000.01,10,0.01);  }

void test51(void) { num_intTest(0.0,0.0,0.0);  }
void test52(void) { num_intTest(1,1,2.0);  }
void test53(void) { num_intTest(0.0001,0.0,0.0001);  }
void test54(void) { num_intTest(10001.0000011,01109.0000090,11110.0000101);  }
void test55(void) { num_intTest(100.01,1,101.01);  }

void test61(void) { num_diffTest(0.0,0.0,0.0);  }
void test62(void) { num_diffTest(1,1,2.0);  }
void test63(void) { num_diffTest(0.0001,0.0,0.0001);  }
void test64(void) { num_diffTest(10001.0000011,01109.0000090,11110.0000101);  }
void test65(void) { num_diffTest(100.01,1,101.01);  }


void addTest(float a, float b, float exp){
  float act = add(a,b);
  printf("Actual:%16.6f... Expected:%16.6f...", act, exp);
  CU_ASSERT_EQUAL(act, exp);

}

void subTest(float a, float b, float exp){
  float act = sub(a,b);
  printf("Actual:%16.6f... Expected:%16.6f...", act, exp);
  CU_ASSERT_EQUAL(act, exp);

}

void multTest(float a, float b, float exp){
  float act = mult(a,b);
  printf("Actual:%16.6f... Expected:%16.6f...", act, exp);
  CU_ASSERT_EQUAL(act, exp);

}

void divTest(float a, float b, float exp){
  float act = div(a,b);
  printf("Actual:%16.6f... Expected:%16.6f...", act, exp);
  CU_ASSERT_EQUAL(act, exp);

}

void modTest(float a, float b, float exp){
  float act = mod(a,b);
  printf("Actual:%16.6f... Expected:%16.6f...", act, exp);
  CU_ASSERT_EQUAL(act, exp);

}

void num_intTest(float a, float b, float exp){
  float act = num_int(a,b);
  printf("Actual:%16.6f... Expected:%16.6f...", act, exp);
  CU_ASSERT_EQUAL(act, exp);

}

void num_diffTest(float a, float b, float exp){
  float act = num_diff(a,b);
  printf("Actual:%16.6f... Expected:%16.6f...", act, exp);
  CU_ASSERT_EQUAL(act, exp);

}


int main() {
  CU_pSuite Suite = NULL;
  if (CUE_SUCCESS != CU_initialize_registry()) { return CU_get_error(); }
  Suite = CU_add_suite("Suite_of_tests_with_valid_inputs", NULL, NULL);
  if (NULL == Suite) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if ( (    NULL == CU_add_test(Suite, "test01", test01) 
	 || NULL == CU_add_test(Suite, "test02", test02) 
	 || NULL == CU_add_test(Suite, "test03", test03) 
	 || NULL == CU_add_test(Suite, "test04", test04)
         || NULL == CU_add_test(Suite, "test05", test05)/*
	 || NULL == CU_add_test(Suite, "test06", test06) 
	 || NULL == CU_add_test(Suite, "test07", test07)
	 || NULL == CU_add_test(Suite, "test10", test10)*/
	 || NULL == CU_add_test(Suite, "test11", test11)
	 || NULL == CU_add_test(Suite, "test12", test12)
	 || NULL == CU_add_test(Suite, "test13", test13)
	 || NULL == CU_add_test(Suite, "test14", test14)
	 || NULL == CU_add_test(Suite, "test15", test15)/*
	 || NULL == CU_add_test(Suite, "test16", test16)
	 || NULL == CU_add_test(Suite, "test17", test17)
         || NULL == CU_add_test(Suite, "test18", test18)
	 || NULL == CU_add_test(Suite, "test19", test19)
	 || NULL == CU_add_test(Suite, "test1A", test1A)
	 || NULL == CU_add_test(Suite, "test1B", test1B)
	 || NULL == CU_add_test(Suite, "test1C", test1C)
	 || NULL == CU_add_test(Suite, "test1D", test1D)
	 || NULL == CU_add_test(Suite, "test1E", test1E)
	 || NULL == CU_add_test(Suite, "test20", test20)*/
	 || NULL == CU_add_test(Suite, "test21", test21)
	 || NULL == CU_add_test(Suite, "test22", test22)
	 || NULL == CU_add_test(Suite, "test23", test23)
	 || NULL == CU_add_test(Suite, "test24", test24)
	 || NULL == CU_add_test(Suite, "test25", test25)/*
	 || NULL == CU_add_test(Suite, "test26", test26)
	 || NULL == CU_add_test(Suite, "test30", test30)*/
	 || NULL == CU_add_test(Suite, "test31", test31)
	 || NULL == CU_add_test(Suite, "test32", test32)
	 || NULL == CU_add_test(Suite, "test33", test33)
	 || NULL == CU_add_test(Suite, "test34", test34)
	 || NULL == CU_add_test(Suite, "test35", test35)/*
	 || NULL == CU_add_test(Suite, "test36", test36)
	 || NULL == CU_add_test(Suite, "test37", test37)
	 || NULL == CU_add_test(Suite, "test40", test40)*/
	 || NULL == CU_add_test(Suite, "test41", test41)
	 || NULL == CU_add_test(Suite, "test42", test42)
	 || NULL == CU_add_test(Suite, "test43", test43)
	 || NULL == CU_add_test(Suite, "test44", test44)
	 || NULL == CU_add_test(Suite, "test45", test45)/*
	 || NULL == CU_add_test(Suite, "test46", test46)
	 || NULL == CU_add_test(Suite, "test47", test47)
	 || NULL == CU_add_test(Suite, "test50", test50)*/
	 || NULL == CU_add_test(Suite, "test51", test51)
	 || NULL == CU_add_test(Suite, "test52", test52)
	 || NULL == CU_add_test(Suite, "test53", test53)
	 || NULL == CU_add_test(Suite, "test54", test54)
	 || NULL == CU_add_test(Suite, "test55", test55)/*
	 || NULL == CU_add_test(Suite, "test56", test56)
	 || NULL == CU_add_test(Suite, "test57", test57)*/
	 || NULL == CU_add_test(Suite, "test61", test61)
	 || NULL == CU_add_test(Suite, "test62", test62)
	 || NULL == CU_add_test(Suite, "test63", test63)
	 || NULL == CU_add_test(Suite, "test64", test64)
	 || NULL == CU_add_test(Suite, "test65", test65)
	 
	) ) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  //  CU_set_output_filename("test");
  //  CU_automated_run_tests();
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}
