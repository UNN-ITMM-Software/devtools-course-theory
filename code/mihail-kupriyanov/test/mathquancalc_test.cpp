// Copyright 2013 Michail Kupriyanov

#include <gtest/gtest.h>

#include <limits.h>
#include <string>
#include <vector>

#include "library/mathquancalc.h"

class MathQuanCalcTest : public ::testing::Test {
 protected:
    MathQuanCalc calc;
    std::vector<MathQuanCalc::Event> sample;

    void AddEvent(double value, double prob) {
        MathQuanCalc::Event e;
        e.probability = prob;
        e.value = value;
        sample.push_back(e);
    }
};

TEST_F(MathQuanCalcTest, Do_Throw_Exception_When_Put_Wrong_Probabilities) {
    AddEvent(1, 0.1);
    AddEvent(2, 0.2);
    EXPECT_THROW(calc.PutSample(sample), std::string);
}

TEST_F(MathQuanCalcTest, Do_Throw_Exception_When_Put_Wrong_Values) {
    AddEvent(1, 0.5);
    AddEvent(1, 0.5);
    EXPECT_THROW(calc.PutSample(sample), std::string);
}

TEST_F(MathQuanCalcTest, Can_Calc_Expected_Value) {
    AddEvent(1, 0.5);
    AddEvent(2, 0.5);
    calc.PutSample(sample);
    EXPECT_EQ(1.5, calc.GetExpectedValue());
}

TEST_F(MathQuanCalcTest, Can_Calc_Dispersion) {
    AddEvent(1, 0.5);
    AddEvent(2, 0.5);
    calc.PutSample(sample);
    EXPECT_EQ(0.25, calc.GetDispersion());
}

TEST_F(MathQuanCalcTest, Can_Calc_Primary_Moment_2) {
    AddEvent(1, 0.5);
    AddEvent(2, 0.5);
    calc.PutSample(sample);
    EXPECT_EQ(2.5, calc.GetPrimaryMoment(2));
}

TEST_F(MathQuanCalcTest, Can_Calc_Central_Moment_3) {
    AddEvent(1, 0.5);
    AddEvent(2, 0.5);
    calc.PutSample(sample);
    EXPECT_EQ(0, calc.GetCentralMoment(3));
}
