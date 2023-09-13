{ lib, stdenv, cmake, ninja, clang-tools_16, cmake-language-server}:
stdenv.mkDerivation {
  pname = "simd";
  version = "0.1.0";

  src = ./.;

  nativeBuildInputs = [
    cmake
    ninja
    clang-tools_16
    cmake-language-server
  ];

  meta = with lib; {
    description = "SIMD Exploration";
  };
}
