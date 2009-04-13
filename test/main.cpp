
void matrix_construction();
void matrix_access();
void test_cblas_dgemm();
void test_t_cblas_dgemm();
void test_basic_alloc();
void test_asum();
void test_axpy();
void test_copy();
void test_dot();
void test_sdot();
void test_dotc();
void test_dotu();
void test_nrm2();
void test_rot();
void test_rotg();
void test_scal();
void test_swap();
void test_iamax();
void test_iamin();
void test_dcabs1();
void test_gemv();
void test_gemm();
void test_vmul();
void test_vml();

int main()
{
  matrix_construction();
  matrix_access();
  test_cblas_dgemm();
  test_basic_alloc();
  test_asum();
  test_axpy();
  test_copy();
  test_dot();
  test_sdot();
  test_dotc();
  test_dotu();
  test_nrm2();
  test_rot();
  test_rotg();
  test_scal();
  test_swap();
  test_iamax();
  test_iamin();
  test_dcabs1();
  test_gemv();
  test_gemm();
  test_vmul();
  test_vml();
  return 0;
}
