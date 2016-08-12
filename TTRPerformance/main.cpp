#include "stdafx.h"
#include "Values.h"
#include "FIX44\MessageCracker.h"
#include "FIX44\TradeTransactionReport.h"


FIX44::TradeTransactionReport CreateTradeTransactionReport()
{
  FIX44::TradeTransactionReport fixReport(FIX::TradeReportID("1234567"));

  fixReport.set(FIX::TradeTransReportType(FIX::TradeTransReportType_PositionClosed));
  fixReport.set(FIX::TradeTransReason(FIX::TradeTransReason_DealerDecision));
  fixReport.set(FIX::OrderID("1234567"));
  fixReport.set(FIX::AccBalance(1000000.0));
  fixReport.set(FIX::AccTrAmount(20.0));
  fixReport.set(FIX::AccTrCurry("USD"));
  fixReport.set(FIX::ClOrdID("ClientOrderId"));
  fixReport.set(FIX::OrderQty(100000.0));
  fixReport.set(FIX::OrderLeavesQty(50000.0));
  fixReport.set(FIX::OrderPrice(1.23456));
  fixReport.set(FIX::OrdType(FIX::OrdType_POSITION));
  fixReport.set(FIX::ParentOrderType(FIX::ParentOrderType_MARKET));
  fixReport.set(FIX::Side(FIX::Side_BUY));
  fixReport.set(FIX::Symbol("EURUSD"));
  fixReport.set(FIX::OrdCreated(FIX::UtcTimeStamp(10, 10, 10, 100, 10, 10, 2016)));
  fixReport.set(FIX::OrdModified(FIX::UtcTimeStamp(10, 10, 10, 100, 10, 10, 2016)));
  fixReport.set(FIX::PosID("123456"));
  fixReport.set(FIX::PosOpened(FIX::UtcTimeStamp(10, 10, 10, 100, 10, 10, 2016)));
  fixReport.set(FIX::PosOpenPrice(1.23456));
  fixReport.set(FIX::PosQty(10000.0));
  fixReport.set(FIX::PosLastQty(1000.0));
  fixReport.set(FIX::PosLeavesQty(1000.0));
  fixReport.set(FIX::PosClosePrice(1.23456));
  fixReport.set(FIX::PosClosed(FIX::UtcTimeStamp(10, 10, 10, 100, 10, 10, 2016)));
  fixReport.set(FIX::Commission(12.0));
  fixReport.set(FIX::CommType(FIX::CommType_ABSOLUTE));
  fixReport.set(FIX::CommCurrency("USD"));
  fixReport.set(FIX::Swap(4.0));
  fixReport.set(FIX::StopLoss(1.23456));
  fixReport.set(FIX::TakeProfit(1.23456));
  fixReport.set(FIX::EncodedCommentLen(11));
  fixReport.set(FIX::EncodedComment("UserComment"));
  fixReport.set(FIX::MarginRateInitial(1.12));
  fixReport.set(FIX::TransactTime(FIX::UtcTimeStamp(10, 10, 10, 100, 10, 10, 2016)));
  fixReport.set(FIX::LastPx(1.234));
  fixReport.set(FIX::LastQty(1000.0));
  fixReport.set(FIX::ParentOrderID("1234567"));
  fixReport.set(FIX::OpenConversionRate(1.123));
  fixReport.set(FIX::CloseConversionRate(1.1234));
  fixReport.set(FIX::ActionID(3));
  fixReport.set(FIX::PosRemainingPrice(1.2345));
  fixReport.set(FIX::PosRemainingSide(FIX::PosRemainingSide_BUY));
  fixReport.set(FIX::ExpireTime(FIX::UtcTimeStamp(11, 11, 11, 100, 11, 11, 2016)));

  return fixReport;
}


int _tmain(int argc, _TCHAR* argv[])
{
  using namespace std::chrono;

  const int steps = 3;
  
  int reports[steps] = { 100000, 200000, 300000 };

  int totReports = 0;
  __int64 totDuration = 0;
  double totAverage = 0;
  double totRepSec = 0;

  for (int c = 0; c < steps; c++)
  {
    int count = reports[c];

    steady_clock::time_point tStart = high_resolution_clock::now();

    for (int i = 0; i < count; i++)
    {
      FIX44::TradeTransactionReport report = CreateTradeTransactionReport();
      std::string repStr = report.toString();
    }

    steady_clock::time_point tStop = high_resolution_clock::now();
    milliseconds time_span = duration_cast<milliseconds>(tStop - tStart);

    __int64 duration = time_span.count();
    double average = (double)duration / (double)count;
    double repSec = 1000.0 / average;

    std::cout << "Reports: " << count << "   Duration: " << duration << " ms   Average: " << average << " ms   Rep/sec: " << repSec << std::endl;

    totReports += count;
    totDuration += duration;
    totAverage += average;
    totRepSec += repSec;

  }

  std::cout << "Summary:" << std::endl
    << "Reports: " << totReports << "   Duration: " << totDuration << " ms   Average: " << totAverage/steps << " ms   Rep/sec: " << totRepSec/steps << std::endl;

  std::cin.get();

  return 0;
}