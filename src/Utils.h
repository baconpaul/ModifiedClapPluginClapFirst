#pragma once


namespace utils
{

static constexpr auto minusInfinitydB = -96.0;
static constexpr auto twelvedBGain = 3.9810717874921617;  // decibelsToGain(12.0)

double decibelsToGain(double decibels)
{
    return decibels > minusInfinitydB ? std::pow(10.0f, decibels * 0.05f)
                                      : 0.0;
}

double gainToDecibels(double gain)
{
    return gain > double() ? std::max(minusInfinitydB, std::log10f(gain) * 20.0)
                           : minusInfinitydB;
}

double toExponentialCurve(double linearValue)
{
    return std::pow(linearValue, 3) * twelvedBGain;
}

double toLinearCurve(double exponentialValue)
{
    return std::cbrt(exponentialValue / twelvedBGain);
}

}
