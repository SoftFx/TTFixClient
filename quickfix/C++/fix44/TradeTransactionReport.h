#ifndef FIX44_TRADETRANSACTIONREPORT_H
#define FIX44_TRADETRANSACTIONREPORT_H

#include "Message.h"

namespace FIX44
{

  class TradeTransactionReport : public Message
  {
  public:
    TradeTransactionReport() : Message(MsgType()) {}
    TradeTransactionReport(const FIX::Message& m) : Message(m) {}
    TradeTransactionReport(const Message& m) : Message(m) {}
    TradeTransactionReport(const TradeTransactionReport& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U1017"); }

    TradeTransactionReport(
      const FIX::TradeReportID& aTradeReportID )
    : Message(MsgType())
    {
      set(aTradeReportID);
    }

    FIELD_SET(*this, FIX::TradeReportID);
    FIELD_SET(*this, FIX::TradeRequestID);
    FIELD_SET(*this, FIX::TradeTransReportType);
    FIELD_SET(*this, FIX::TradeTransReason);
    FIELD_SET(*this, FIX::TransactTime);
    FIELD_SET(*this, FIX::AccBalance);
    FIELD_SET(*this, FIX::AccTrAmount);
    FIELD_SET(*this, FIX::AccTrCurry);
    FIELD_SET(*this, FIX::OrderID);
    FIELD_SET(*this, FIX::ActionID);
    FIELD_SET(*this, FIX::ClOrdID);
    FIELD_SET(*this, FIX::OrderQty);
    FIELD_SET(*this, FIX::HiddenQty);
    FIELD_SET(*this, FIX::MaxVisibleQty);
    FIELD_SET(*this, FIX::OrderLeavesQty);
    FIELD_SET(*this, FIX::OrderPrice);
    FIELD_SET(*this, FIX::OrderStopPx);
    FIELD_SET(*this, FIX::OrdType);
    FIELD_SET(*this, FIX::Side);
    FIELD_SET(*this, FIX::Symbol);
    FIELD_SET(*this, FIX::OrdCreated);
    FIELD_SET(*this, FIX::OrdModified);
    FIELD_SET(*this, FIX::PosID);
    FIELD_SET(*this, FIX::PosByID);
    FIELD_SET(*this, FIX::PosOpened);
    FIELD_SET(*this, FIX::PosOpenReqPrice);
    FIELD_SET(*this, FIX::PosOpenPrice);
    FIELD_SET(*this, FIX::PosQty);
    FIELD_SET(*this, FIX::PosLastQty);
    FIELD_SET(*this, FIX::PosLeavesQty);
    FIELD_SET(*this, FIX::PosCloseReqPrice);
    FIELD_SET(*this, FIX::PosClosePrice);
    FIELD_SET(*this, FIX::PosClosed);
    FIELD_SET(*this, FIX::PosModified);
    FIELD_SET(*this, FIX::PosRemainingSide);
    FIELD_SET(*this, FIX::PosRemainingPrice);
    FIELD_SET(*this, FIX::Commission);
    FIELD_SET(*this, FIX::CommType);
    FIELD_SET(*this, FIX::CommCurrency);
    FIELD_SET(*this, FIX::FundRenewWaiv);
    FIELD_SET(*this, FIX::AgentCommission);
    FIELD_SET(*this, FIX::AgentCommType);
    FIELD_SET(*this, FIX::AgentCommCurrency);
    FIELD_SET(*this, FIX::Swap);
    FIELD_SET(*this, FIX::StopLoss);
    FIELD_SET(*this, FIX::TakeProfit);
    FIELD_SET(*this, FIX::EncodedCommentLen);
    FIELD_SET(*this, FIX::EncodedComment);
    FIELD_SET(*this, FIX::EncodedTagLen);
    FIELD_SET(*this, FIX::EncodedTag);
    FIELD_SET(*this, FIX::Magic);
    FIELD_SET(*this, FIX::MarginRateInitial);
    FIELD_SET(*this, FIX::LastQty);
    FIELD_SET(*this, FIX::LastPx);
    FIELD_SET(*this, FIX::OpenConversionRate);
    FIELD_SET(*this, FIX::CloseConversionRate);
    FIELD_SET(*this, FIX::ParentOrderID);
    FIELD_SET(*this, FIX::ParentOrderType);
    FIELD_SET(*this, FIX::ExpireDate);
    FIELD_SET(*this, FIX::ExpireTime);
    FIELD_SET(*this, FIX::ReqOpenPrice);
    FIELD_SET(*this, FIX::ReqOpenQty);
    FIELD_SET(*this, FIX::ReqClosePrice);
    FIELD_SET(*this, FIX::ReqCloseQty);
    FIELD_SET(*this, FIX::ImmediateOrCancelFlag);
    FIELD_SET(*this, FIX::MarketWithSlippageFlag);
    FIELD_SET(*this, FIX::SrcAssetCurrency);
    FIELD_SET(*this, FIX::SrcAssetAmount);
    FIELD_SET(*this, FIX::SrcAssetMovement);
    FIELD_SET(*this, FIX::DstAssetCurrency);
    FIELD_SET(*this, FIX::DstAssetAmount);
    FIELD_SET(*this, FIX::DstAssetMovement);
    FIELD_SET(*this, FIX::MarginCurrencyToUsdConversionRate);
    FIELD_SET(*this, FIX::UsdToMarginCurrencyConversionRate);
    FIELD_SET(*this, FIX::MarginCurrency);
    FIELD_SET(*this, FIX::ProfitCurrencyToUsdConversionRate);
    FIELD_SET(*this, FIX::UsdToProfitCurrencyConversionRate);
    FIELD_SET(*this, FIX::ProfitCurrency);
    FIELD_SET(*this, FIX::SrcAssetToUsdConversionRate);
    FIELD_SET(*this, FIX::UsdToSrcAssetConversionRate);
    FIELD_SET(*this, FIX::DstAssetToUsdConversionRate);
    FIELD_SET(*this, FIX::UsdToDstAssetConversionRate);
    FIELD_SET(*this, FIX::CommOpenReducedFlag);
    FIELD_SET(*this, FIX::CommCloseReducedFlag);
    FIELD_SET(*this, FIX::MinCommissionCurrency);
    FIELD_SET(*this, FIX::MinCommissionConversionRate);
    FIELD_SET(*this, FIX::Slippage);
    FIELD_SET(*this, FIX::MarginCurrencyToReportConversionRate);
    FIELD_SET(*this, FIX::ReportToMarginCurrencyConversionRate);
    FIELD_SET(*this, FIX::ProfitCurrencyToReportConversionRate);
    FIELD_SET(*this, FIX::ReportToProfitCurrencyConversionRate);
    FIELD_SET(*this, FIX::SrcAssetToReportConversionRate);
    FIELD_SET(*this, FIX::ReportToSrcAssetConversionRate);
    FIELD_SET(*this, FIX::DstAssetToReportConversionRate);
    FIELD_SET(*this, FIX::ReportToDstAssetConversionRate);
    FIELD_SET(*this, FIX::ReportCurrency);
    FIELD_SET(*this, FIX::TokenCommissionCurrency);
    FIELD_SET(*this, FIX::TokenCommissionCurrencyDiscount);
    FIELD_SET(*this, FIX::TokenCommissionConversionRate);
  };

}

#endif
