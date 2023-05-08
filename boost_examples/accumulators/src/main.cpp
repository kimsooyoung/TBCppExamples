#include <iostream>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/stats.hpp>
#include <boost/accumulators/statistics/mean.hpp>
#include <boost/accumulators/statistics/moment.hpp>
#include <boost/accumulators/statistics/rolling_mean.hpp>

namespace bacc = boost::accumulators;

int main()
{
  // Define an accumulator set for calculating the mean and the
  // 2nd moment ...
  {
    bacc::accumulator_set<double, bacc::stats<bacc::tag::mean, bacc::tag::moment<2> > > acc;

    // push in some data ...
    acc(1.2);
    acc(2.3);
    acc(3.4);
    acc(4.5);

    // Display the results ...
    std::cout << "Mean:   " << bacc::mean(acc) << std::endl;
    std::cout << "Moment: " << bacc::moment<2>(acc) << std::endl;
  }

  {
    bacc::accumulator_set<int, bacc::stats<bacc::tag::rolling_mean> > acc(bacc::tag::rolling_window::window_size = 5);

    acc(10);
    acc(10);
    acc(10);
    acc(10);
    acc(10);
    std::cout << "rolling_mean :  " << bacc::rolling_mean(acc) << std::endl;

    acc(5);
    std::cout << "rolling_mean :  " << bacc::rolling_mean(acc) << std::endl;

    acc(5);
    std::cout << "rolling_mean :  " << bacc::rolling_mean(acc) << std::endl;

    acc(5);
    std::cout << "rolling_mean :  " << bacc::rolling_mean(acc) << std::endl;

  }

  return 0;
}