#include <immintrin.h>

#include <chrono>
#include <iostream>
#include <ranges>

class Vector4d {

public:
  double data[4];
  constexpr double w() const { return data[0]; }
  constexpr double x() const { return data[1]; }
  constexpr double y() const { return data[2]; }
  constexpr double z() const { return data[3]; }

  Vector4d() noexcept {}
  Vector4d(double w, double x, double y, double z) noexcept
      : data{w, x, y, z} {}
};

Vector4d operator+(const Vector4d &a, const Vector4d &b) {
  const auto avec = _mm256_load_pd(a.data);
  const auto bvec = _mm256_load_pd(b.data);
  const auto cvec = _mm256_add_pd(avec, bvec);

  Vector4d c;
  _mm256_store_pd(c.data, cvec);

  return c;
}

Vector4d operator-(const Vector4d &a, const Vector4d &b) {
  const auto avec = _mm256_load_pd(a.data);
  const auto bvec = _mm256_load_pd(b.data);
  const auto cvec = _mm256_sub_pd(avec, bvec);

  Vector4d c;
  _mm256_store_pd(c.data, cvec);

  return c;
}

Vector4d operator*(const Vector4d a, const Vector4d &b) {
  const auto avec = _mm256_load_pd(a.data);
  const auto bvec = _mm256_load_pd(b.data);
  const auto cvec = _mm256_mul_pd(avec, bvec);

  Vector4d c;
  _mm256_store_pd(c.data, cvec);

  return c;
}

Vector4d operator/(const Vector4d a, const Vector4d &b) {
  const auto avec = _mm256_load_pd(a.data);
  const auto bvec = _mm256_load_pd(b.data);
  const auto cvec = _mm256_div_pd(avec, bvec);

  Vector4d c;
  _mm256_store_pd(c.data, cvec);

  return c;
}

int main(int argc, char *argv[]) {
  const Vector4d x(-1.0, 1.0, 2.0, 3.0);
  std::cout << x.w() << ", " << x.x() << ", " << x.y() << ", " << x.z()
            << std::endl;

  const auto y_start = std::chrono::system_clock::now();
  const Vector4d y = x + x;
  const auto y_end = std::chrono::system_clock::now();
  std::cout << y_end - y_start << ": " << y.w() << ", " << y.x() << ", "
            << y.y() << ", " << y.z() << std::endl;

  const auto z_start = std::chrono::system_clock::now();
  const Vector4d z = x - y;
  const auto z_end = std::chrono::system_clock::now();
  std::cout << z_end - z_start << ": " << z.w() << ", " << z.x() << ", "
            << z.y() << ", " << z.z() << std::endl;

  const auto d_start = std::chrono::system_clock::now();
  const Vector4d d = x * y;
  const auto d_end = std::chrono::system_clock::now();
  std::cout << d_end - d_start << ": " << d.w() << ", " << d.x() << ", "
            << d.y() << ", " << d.z() << std::endl;

  const auto e_start = std::chrono::system_clock::now();
  const Vector4d e = x / y;
  const auto e_end = std::chrono::system_clock::now();
  std::cout << e_end - e_start << ": " << e.w() << ", " << e.x() << ", "
            << e.y() << ", " << e.z() << std::endl;

  return 0;
}