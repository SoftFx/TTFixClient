#ifndef FIX44_ACCOUNTINFO_H
#define FIX44_ACCOUNTINFO_H

#include "Message.h"

namespace FIX44
{

  class AccountInfo : public Message
  {
  public:
    AccountInfo() : Message(MsgType()) {}
    AccountInfo(const FIX::Message& m) : Message(m) {}
    AccountInfo(const Message& m) : Message(m) {}
    AccountInfo(const AccountInfo& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("U1006"); }

    AccountInfo(
      const FIX::Leverage& aLeverage,
      const FIX::Balance& aBalance,
      const FIX::Margin& aMargin,
      const FIX::Equity& aEquity,
      const FIX::Currency& aCurrency,
      const FIX::Account& aAccount )
    : Message(MsgType())
    {
      set(aLeverage);
      set(aBalance);
      set(aMargin);
      set(aEquity);
      set(aCurrency);
      set(aAccount);
    }

    FIELD_SET(*this, FIX::AcInfReqID);
    FIELD_SET(*this, FIX::Leverage);
    FIELD_SET(*this, FIX::Balance);
    FIELD_SET(*this, FIX::Margin);
    FIELD_SET(*this, FIX::Equity);
    FIELD_SET(*this, FIX::Currency);
    FIELD_SET(*this, FIX::Account);
    FIELD_SET(*this, FIX::AccountingType);
    FIELD_SET(*this, FIX::AccMarginCallLevel);
    FIELD_SET(*this, FIX::AccStopOutLevel);
    FIELD_SET(*this, FIX::AccountValidFlag);
    FIELD_SET(*this, FIX::AccountBlockedFlag);
    FIELD_SET(*this, FIX::InvestorLoginFlag);
    FIELD_SET(*this, FIX::TwoFactorAuthFlag);
    FIELD_SET(*this, FIX::AccountName);
    FIELD_SET(*this, FIX::RegistEmail);
    FIELD_SET(*this, FIX::RegistDate);
    FIELD_SET(*this, FIX::ModifyTime);
    FIELD_SET(*this, FIX::EncodedCommentLen);
    FIELD_SET(*this, FIX::EncodedComment);
    FIELD_SET(*this, FIX::NoAssets);
    class NoAssets: public FIX::Group
    {
    public:
    NoAssets() : FIX::Group(10117,10118,FIX::message_order(10118,10154,10119,10120,10201,10202,10236,10237,0)) {}
      FIELD_SET(*this, FIX::AssetBalance);
      FIELD_SET(*this, FIX::AssetLockedAmt);
      FIELD_SET(*this, FIX::AssetTradeAmt);
      FIELD_SET(*this, FIX::AssetCurrency);
      FIELD_SET(*this, FIX::SrcAssetToUsdConversionRate);
      FIELD_SET(*this, FIX::UsdToSrcAssetConversionRate);
      FIELD_SET(*this, FIX::SrcAssetToReportConversionRate);
      FIELD_SET(*this, FIX::ReportToSrcAssetConversionRate);
    };
    FIELD_SET(*this, FIX::SessionsPerAccount);
    FIELD_SET(*this, FIX::RequestsPerSecond);
    FIELD_SET(*this, FIX::ThrottlingMethodsInfo);
    class ThrottlingMethodsInfo: public FIX::Group
    {
    public:
    ThrottlingMethodsInfo() : FIX::Group(10229,10228,FIX::message_order(10228,10227,0)) {}
      FIELD_SET(*this, FIX::ThrottlingMethod);
      FIELD_SET(*this, FIX::RequestsPerSecond);
    };
    FIELD_SET(*this, FIX::ReportCurrency);
    FIELD_SET(*this, FIX::TokenCommissionCurrency);
    FIELD_SET(*this, FIX::TokenCommissionCurrencyDiscount);
    FIELD_SET(*this, FIX::TokenCommissionEnabled);
  };

}

#endif
