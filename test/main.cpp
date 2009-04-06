
void matrix_construction();
void matrix_access();
void test_cblas_dgemm();
void test_t_cblas_dgemm();
void test_basic_alloc();
void test_asum();

int main()
{
  matrix_construction();
  matrix_access();
  test_cblas_dgemm();
  test_basic_alloc();
  test_asum();
  return 0;
}
