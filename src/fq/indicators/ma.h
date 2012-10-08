#ifndef FQ_INDICATORS_MA_H
#define FQ_INDICATORS_MA_H

#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/stats.hpp>
#include <boost/accumulators/statistics/rolling_mean.hpp>

#include <fq/indicators/indicator.h>


namespace FreeQuant { namespace Indicators {

class MA : public Indicator {
public:
    MA() : acc(boost::accumulators::tag::rolling_window::window_size = 5) {}
    void onBar(const FreeQuant::MarketData::Bar& bar) {
        acc(bar.typical());
    }

    double value() const {
        return boost::accumulators::rolling_mean(acc);
    }
private:
    boost::accumulators::accumulator_set<
        double,
        boost::accumulators::stats<boost::accumulators::tag::rolling_mean>
    > acc;
};

}}

#endif // MA_H
