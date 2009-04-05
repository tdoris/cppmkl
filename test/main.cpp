
void matrix_construction();
void matrix_access();
void test_cblas_dgemm();
void test_t_cblas_dgemm();
void test_basic_alloc();

int main()
{
  matrix_construction();
  matrix_access();
  test_cblas_dgemm();
  test_basic_alloc();
  return 0;
}
