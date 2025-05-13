#include <gtest/gtest.h>
#include <cmath>
#include <chrono>
#include <iostream>
#include <string>

void Nanosec(std::string name, void(*fn)()) {
    auto a = std::chrono::high_resolution_clock::now();
    fn();
    auto b = std::chrono::high_resolution_clock::now();
    auto t = std::chrono::duration_cast<std::chrono::nanoseconds>(b - a).count();
    std::cout << name << " time:" << t << "ns" << std::endl;
}


void testAbsValue() {
    EXPECT_EQ(std::abs(-2147483648), 2147483648);
    EXPECT_EQ(std::abs(0), 0);
    EXPECT_EQ(std::abs(2147483648), 2147483648);
    EXPECT_EQ(std::abs(-1), 1);
    EXPECT_EQ(std::abs(1), 1);
    EXPECT_EQ(std::abs(350.15), 350.15);
    EXPECT_EQ(std::abs(-350.15), 350.15);
}
TEST(CMathTest, AbsValue) {
    Nanosec("AbsValue: ",testAbsValue);
}


void testAcos() {
    EXPECT_NEAR(std::acos(0), 1.5708, 0.0001);
    EXPECT_NEAR(std::acos(1), 0, 0.0001);
    EXPECT_NEAR(std::acos(-1), 3.1416, 0.0001);
}
TEST(CMathTest, Acos) {
    Nanosec("Acos: ",testAcos);
}


void testAsin() {
    EXPECT_NEAR(std::asin(0), 0, 0.0001);
    EXPECT_NEAR(std::asin(1), 1.5708, 0.0001);
    EXPECT_NEAR(std::asin(-1), -1.5708, 0.0001);
}
TEST(CMathTest, Asin) {
    Nanosec("Asin: ",testAsin);
}


void testAtan() {
    EXPECT_NEAR(std::atan(0), 0, 0.0001);
    EXPECT_NEAR(std::atan(1), 0.7854, 0.0001);
    EXPECT_NEAR(std::atan(-1), -0.7854, 0.0001);
}
TEST(CMathTest, Atan) {
    Nanosec("Atan: ",testAtan);
}



void testAtan2() {
    EXPECT_NEAR(std::atan2(1, 1), 0.7854, 0.0001);
    EXPECT_NEAR(std::atan2(1, -1), 2.35619, 0.0001);
}
TEST(CMathTest, Atan2) {
    Nanosec("Atan2: ", testAtan2);
}


void testCbrt() {
    EXPECT_NEAR(std::cbrt(27), 3, 0.0001);
    EXPECT_NEAR(std::cbrt(-8), -2, 0.0001);
    EXPECT_NEAR(std::cbrt(6.2), 1.8371, 0.0001);
}
TEST(CMathTest, Cbrt) {
    Nanosec("Cbrt: ", testCbrt);
}


void testCeil() {
    EXPECT_EQ(std::ceil(2.3), 3);
    EXPECT_EQ(std::ceil(-2.6), -2);
    EXPECT_EQ(std::ceil(0), 0);
}
TEST(CMathTest, Ceil) {
    Nanosec("Ceil: ", testCeil);
}


void testCopysign() {
    EXPECT_EQ(std::copysign(3, -1), -3);
    EXPECT_EQ(std::copysign(-4, 1), 4);
    EXPECT_EQ(std::copysign(-0, -1), 0);
}
TEST(CMathTest, Copysign) {
    Nanosec("Copysign: ", testCopysign);
}


void testCos() {
    EXPECT_NEAR(std::cos(0), 1, 0.0001);
    EXPECT_NEAR(std::cos(3.14159), -1, 0.0001);
    EXPECT_NEAR(std::cos(-1), 0.540303, 0.0001);
}
TEST(CMathTest, Cos) {
    Nanosec("Cos: ", testCos);
}


void testExp() {
    EXPECT_NEAR(std::exp(1), 2.71828, 0.0001);
    EXPECT_NEAR(std::exp(0), 1, 0.0001);
    EXPECT_NEAR(std::exp(2.3), 9.9742, 0.0001);
}
TEST(CMathTest, Exp) {
    Nanosec("Exp: ", testExp);
}


void testExp2() {
    EXPECT_NEAR(std::exp2(3), 8, 0.0001);
    EXPECT_NEAR(std::exp2(0), 1, 0.0001);
    EXPECT_NEAR(std::exp2(9.2), 588.13355, 0.0001);
}
TEST(CMathTest, Exp2) {
    Nanosec("Exp2: ", testExp2);
}


void testExpm1() {
    EXPECT_NEAR(std::expm1(1), 1.71828, 0.0001);
    EXPECT_NEAR(std::expm1(0), 0, 0.0001);
    EXPECT_NEAR(std::expm1(-1), -0.6321, 0.0001);
}
TEST(CMathTest, Expm1) {
    Nanosec("Expm1: ", testExpm1);
}


void testErf() {
    EXPECT_NEAR(std::erf(0), 0, 0.0001);
    EXPECT_NEAR(std::erf(1), 0.8427, 0.0001);
    EXPECT_NEAR(std::erf(-1), -0.8427, 0.0001);
}
TEST(CMathTest, Erf) {
    Nanosec("Erf: ", testErf);
}


void testErfc() {
    EXPECT_NEAR(std::erfc(0), 1, 0.0001);
    EXPECT_NEAR(std::erfc(1), 0.1573, 0.0001);
    EXPECT_NEAR(std::erfc(-1), 1.8427, 0.0001);
}
TEST(CMathTest, Erfc) {
    Nanosec("Erfc: ", testErfc);
}


void testFabs() {
    EXPECT_EQ(std::fabs(-3.14), 3.14);
    EXPECT_EQ(std::fabs(0), 0);
    EXPECT_EQ(std::fabs(5.5), 5.5);
}
TEST(CMathTest, Fabs) {
    Nanosec("Fabs: ", testFabs);
}


void testFdim() {
    EXPECT_EQ(std::fdim(3, 1), 2);
    EXPECT_EQ(std::fdim(1, 3), 0);
    EXPECT_EQ(std::fdim(-1, -3), 2);
}
TEST(CMathTest, Fdim) {
    Nanosec("Fdim: ", testFdim);
}


void testFloor() {
    EXPECT_EQ(std::floor(2.7), 2);
    EXPECT_EQ(std::floor(-2.7), -3);
    EXPECT_EQ(std::floor(0.0), 0);
}
TEST(CMathTest, Floor) {
    Nanosec("Floor: ", testFloor);
}


void testFma() {
    EXPECT_EQ(std::fma(2, 3, 4), 10);
    EXPECT_EQ(std::fma(1, -1, 1), 0);
    EXPECT_EQ(std::fma(0.5, 2, 1), 2);
}
TEST(CMathTest, Fma) {
    Nanosec("Fma: ", testFma);
}


void testFmax() {
    EXPECT_EQ(std::fmax(2, 3), 3);
    EXPECT_EQ(std::fmax(-2, -3), -2);
    EXPECT_EQ(std::fmax(0, -5), 0);
}
TEST(CMathTest, Fmax) {
    Nanosec("Fmax: ", testFmax);
}


void testFmin() {
    EXPECT_EQ(std::fmin(2, 3), 2);
    EXPECT_EQ(std::fmin(-2, -3), -3);
    EXPECT_EQ(std::fmin(0, -5), -5);
}
TEST(CMathTest, Fmin) {
    Nanosec("Fmin: ", testFmin);
}


void testFmod() {
    EXPECT_NEAR(std::fmod(5, 2), 1, 0.0001);
    EXPECT_NEAR(std::fmod(7, 3), 1, 0.0001);
    EXPECT_NEAR(std::fmod(-7, 3), -1, 0.0001);
}
TEST(CMathTest, Fmod) {
    Nanosec("Fmod: ", testFmod);
}


void testFrexp() {
    int exp;
    EXPECT_NEAR(std::frexp(8, &exp), 0.5, 0.0001);
    EXPECT_EQ(exp, 4);
}
TEST(CMathTest, Frexp) {
    Nanosec("Frexp: ", testFrexp);
}


void testHypot() {
    EXPECT_NEAR(std::hypot(3, 4), 5, 0.0001);
    EXPECT_NEAR(std::hypot(1, 1), 1.41421, 0.0001);
    EXPECT_NEAR(std::hypot(5, 12), 13, 0.0001);
}
TEST(CMathTest, Hypot) {
    Nanosec("Hypot: ", testHypot);
}


void testIlogb() {
    EXPECT_EQ(std::ilogb(8), 3);
    EXPECT_EQ(std::ilogb(0.25), -2);
    EXPECT_EQ(std::ilogb(1), 0);
}
TEST(CMathTest, Ilogb) {
    Nanosec("Ilogb: ", testIlogb);
}


void testLdexp() {
    EXPECT_EQ(std::ldexp(1, 3), 8);
    EXPECT_EQ(std::ldexp(0.5, 2), 2);
    EXPECT_EQ(std::ldexp(2, -1), 1);
}
TEST(CMathTest, Ldexp) {
    Nanosec("Ldexp: ", testLdexp);
}


void testLlround() {
    EXPECT_EQ(std::llround(2.3), 2);
    EXPECT_EQ(std::llround(2.7), 3);
    EXPECT_EQ(std::llround(-2.7), -3);
}
TEST(CMathTest, Llround) {
    Nanosec("Llround: ", testLlround);
}


void testLog() {
    EXPECT_NEAR(std::log(1), 0, 0.0001);
    EXPECT_NEAR(std::log(2), 0.69314, 0.0001);
    EXPECT_NEAR(std::log(10), 2.30258, 0.0001);
}
TEST(CMathTest, Log) {
    Nanosec("Log: ", testLog);
}


void testLog10() {
    EXPECT_NEAR(std::log10(10), 1, 0.0001);
    EXPECT_NEAR(std::log10(100), 2, 0.0001);
    EXPECT_NEAR(std::log10(1000), 3, 0.0001);
}
TEST(CMathTest, Log10) {
    Nanosec("Log10: ", testLog10);
}


void testLog1p() {
    EXPECT_NEAR(std::log1p(0), 0, 0.0001);
    EXPECT_NEAR(std::log1p(1), 0.69314, 0.0001);
    EXPECT_NEAR(std::log1p(0.5), 0.40547, 0.0001);
}
TEST(CMathTest, Log1p) {
    Nanosec("Log1p: ", testLog1p);
}


void testLog2() {
    EXPECT_NEAR(std::log2(8), 3, 0.0001);
    EXPECT_NEAR(std::log2(16), 4, 0.0001);
    EXPECT_NEAR(std::log2(32), 5, 0.0001);
}
TEST(CMathTest, Log2) {
    Nanosec("Log2: ", testLog2);
}


void testPow() {
    EXPECT_NEAR(std::pow(2, 3), 8, 0.0001);
    EXPECT_NEAR(std::pow(3, 2), 9, 0.0001);
    EXPECT_NEAR(std::pow(4, 0.5), 2, 0.0001);
}
TEST(CMathTest, Pow) {
    Nanosec("Pow: ", testPow);
}


void testRound() {
    EXPECT_EQ(std::round(2.3), 2);
    EXPECT_EQ(std::round(2.7), 3);
    EXPECT_EQ(std::round(-2.5), -3);  
}
TEST(CMathTest, Round) {
    Nanosec("Round: ", testRound);
}


void testSine() {
    EXPECT_NEAR(std::sin(0), 0, 0.0001);
    EXPECT_NEAR(std::sin(3.14159), 0, 0.0001);
    EXPECT_NEAR(std::sin(3.14159 / 2), 1, 0.0001);
}
TEST(CMathTest, Sine) {
    Nanosec("Sine: ", testSine);
}


void testSqrt() {
    EXPECT_NEAR(std::sqrt(4), 2, 0.0001);
    EXPECT_NEAR(std::sqrt(9), 3, 0.0001);
    EXPECT_NEAR(std::sqrt(2), 1.41421, 0.0001);
}
TEST(CMathTest, Sqrt) {
    Nanosec("Sqrt: ", testSqrt);
}


void testTan() {
    EXPECT_NEAR(std::tan(0), 0, 0.0001);
    EXPECT_NEAR(std::tan(3.14159 / 4), 1, 0.0001);
    EXPECT_NEAR(std::tan(-3.14159 / 4), -1, 0.0001);
}
TEST(CMathTest, Tan) {
    Nanosec("Tan: ", testTan);
}


void testTrunc() {
    EXPECT_EQ(std::trunc(2.7), 2);
    EXPECT_EQ(std::trunc(-2.7), -2);
    EXPECT_EQ(std::trunc(0.9), 0);
}
TEST(CMathTest, Trunc) {
    Nanosec("Trunc: ", testTrunc);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
