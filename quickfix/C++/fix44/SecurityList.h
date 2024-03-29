#ifndef FIX44_SECURITYLIST_H
#define FIX44_SECURITYLIST_H

#include "Message.h"

namespace FIX44
{

  class SecurityList : public Message
  {
  public:
    SecurityList() : Message(MsgType()) {}
    SecurityList(const FIX::Message& m) : Message(m) {}
    SecurityList(const Message& m) : Message(m) {}
    SecurityList(const SecurityList& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("y"); }

    SecurityList(
      const FIX::SecurityReqID& aSecurityReqID,
      const FIX::SecurityResponseID& aSecurityResponseID,
      const FIX::SecurityRequestResult& aSecurityRequestResult )
    : Message(MsgType())
    {
      set(aSecurityReqID);
      set(aSecurityResponseID);
      set(aSecurityRequestResult);
    }

    FIELD_SET(*this, FIX::SecurityReqID);
    FIELD_SET(*this, FIX::SecurityResponseID);
    FIELD_SET(*this, FIX::SecurityRequestResult);
    FIELD_SET(*this, FIX::TotNoRelatedSym);
    FIELD_SET(*this, FIX::LastFragment);
    FIELD_SET(*this, FIX::NoRelatedSym);
    class NoRelatedSym: public FIX::Group
    {
    public:
    NoRelatedSym() : FIX::Group(146,55,FIX::message_order(55,65,48,22,454,460,461,167,762,200,541,224,225,239,226,227,228,255,543,470,471,472,240,202,947,206,231,223,207,106,348,349,107,350,351,691,667,875,876,864,873,874,668,869,870,913,914,915,918,788,916,917,919,898,711,15,10137,10135,232,555,218,220,221,222,662,663,699,761,235,236,701,696,697,698,10057,561,562,10058,10062,10059,10060,10061,10063,10134,10194,10209,336,625,827,58,354,355,120,10138,10136,10067,12,10123,13,10124,10143,10210,10211,10212,10125,10126,10213,10127,10155,10131,10132,10170,10243,0)) {}
      FIELD_SET(*this, FIX::Symbol);
      FIELD_SET(*this, FIX::SymbolSfx);
      FIELD_SET(*this, FIX::SecurityID);
      FIELD_SET(*this, FIX::SecurityIDSource);
      FIELD_SET(*this, FIX::Product);
      FIELD_SET(*this, FIX::CFICode);
      FIELD_SET(*this, FIX::SecurityType);
      FIELD_SET(*this, FIX::SecuritySubType);
      FIELD_SET(*this, FIX::MaturityMonthYear);
      FIELD_SET(*this, FIX::MaturityDate);
      FIELD_SET(*this, FIX::CouponPaymentDate);
      FIELD_SET(*this, FIX::IssueDate);
      FIELD_SET(*this, FIX::RepoCollateralSecurityType);
      FIELD_SET(*this, FIX::RepurchaseTerm);
      FIELD_SET(*this, FIX::RepurchaseRate);
      FIELD_SET(*this, FIX::Factor);
      FIELD_SET(*this, FIX::CreditRating);
      FIELD_SET(*this, FIX::InstrRegistry);
      FIELD_SET(*this, FIX::CountryOfIssue);
      FIELD_SET(*this, FIX::StateOrProvinceOfIssue);
      FIELD_SET(*this, FIX::LocaleOfIssue);
      FIELD_SET(*this, FIX::RedemptionDate);
      FIELD_SET(*this, FIX::StrikePrice);
      FIELD_SET(*this, FIX::StrikeCurrency);
      FIELD_SET(*this, FIX::OptAttribute);
      FIELD_SET(*this, FIX::ContractMultiplier);
      FIELD_SET(*this, FIX::CouponRate);
      FIELD_SET(*this, FIX::SecurityExchange);
      FIELD_SET(*this, FIX::Issuer);
      FIELD_SET(*this, FIX::EncodedIssuerLen);
      FIELD_SET(*this, FIX::EncodedIssuer);
      FIELD_SET(*this, FIX::SecurityDesc);
      FIELD_SET(*this, FIX::EncodedSecurityDescLen);
      FIELD_SET(*this, FIX::EncodedSecurityDesc);
      FIELD_SET(*this, FIX::Pool);
      FIELD_SET(*this, FIX::ContractSettlMonth);
      FIELD_SET(*this, FIX::CPProgram);
      FIELD_SET(*this, FIX::CPRegType);
      FIELD_SET(*this, FIX::DatedDate);
      FIELD_SET(*this, FIX::InterestAccrualDate);
      FIELD_SET(*this, FIX::NoSecurityAltID);
      class NoSecurityAltID: public FIX::Group
      {
      public:
      NoSecurityAltID() : FIX::Group(454,455,FIX::message_order(455,456,0)) {}
        FIELD_SET(*this, FIX::SecurityAltID);
        FIELD_SET(*this, FIX::SecurityAltIDSource);
      };
      FIELD_SET(*this, FIX::NoEvents);
      class NoEvents: public FIX::Group
      {
      public:
      NoEvents() : FIX::Group(864,865,FIX::message_order(865,866,867,868,0)) {}
        FIELD_SET(*this, FIX::EventType);
        FIELD_SET(*this, FIX::EventDate);
        FIELD_SET(*this, FIX::EventPx);
        FIELD_SET(*this, FIX::EventText);
      };
      FIELD_SET(*this, FIX::DeliveryForm);
      FIELD_SET(*this, FIX::PctAtRisk);
      FIELD_SET(*this, FIX::NoInstrAttrib);
      class NoInstrAttrib: public FIX::Group
      {
      public:
      NoInstrAttrib() : FIX::Group(870,871,FIX::message_order(871,872,0)) {}
        FIELD_SET(*this, FIX::InstrAttribType);
        FIELD_SET(*this, FIX::InstrAttribValue);
      };
      FIELD_SET(*this, FIX::AgreementDesc);
      FIELD_SET(*this, FIX::AgreementID);
      FIELD_SET(*this, FIX::AgreementDate);
      FIELD_SET(*this, FIX::AgreementCurrency);
      FIELD_SET(*this, FIX::TerminationType);
      FIELD_SET(*this, FIX::StartDate);
      FIELD_SET(*this, FIX::EndDate);
      FIELD_SET(*this, FIX::DeliveryType);
      FIELD_SET(*this, FIX::MarginRatio);
      FIELD_SET(*this, FIX::Currency);
      FIELD_SET(*this, FIX::CurrencyPrecision);
      FIELD_SET(*this, FIX::CurrencySortOrder);
      FIELD_SET(*this, FIX::NoStipulations);
      class NoStipulations: public FIX::Group
      {
      public:
      NoStipulations() : FIX::Group(232,233,FIX::message_order(233,234,0)) {}
        FIELD_SET(*this, FIX::StipulationType);
        FIELD_SET(*this, FIX::StipulationValue);
      };
      FIELD_SET(*this, FIX::Spread);
      FIELD_SET(*this, FIX::BenchmarkCurveCurrency);
      FIELD_SET(*this, FIX::BenchmarkCurveName);
      FIELD_SET(*this, FIX::BenchmarkCurvePoint);
      FIELD_SET(*this, FIX::BenchmarkPrice);
      FIELD_SET(*this, FIX::BenchmarkPriceType);
      FIELD_SET(*this, FIX::BenchmarkSecurityID);
      FIELD_SET(*this, FIX::BenchmarkSecurityIDSource);
      FIELD_SET(*this, FIX::YieldType);
      FIELD_SET(*this, FIX::Yield);
      FIELD_SET(*this, FIX::YieldCalcDate);
      FIELD_SET(*this, FIX::YieldRedemptionDate);
      FIELD_SET(*this, FIX::YieldRedemptionPrice);
      FIELD_SET(*this, FIX::YieldRedemptionPriceType);
      FIELD_SET(*this, FIX::PxPrecision);
      FIELD_SET(*this, FIX::RoundLot);
      FIELD_SET(*this, FIX::MinTradeVol);
      FIELD_SET(*this, FIX::MaxTradeVolume);
      FIELD_SET(*this, FIX::TradeVolStep);
      FIELD_SET(*this, FIX::ProfitCalcMode);
      FIELD_SET(*this, FIX::MarginCalcMode);
      FIELD_SET(*this, FIX::MarginHedge);
      FIELD_SET(*this, FIX::MarginFactor);
      FIELD_SET(*this, FIX::MarginFactorFractional);
      FIELD_SET(*this, FIX::StopOrderMarginReduction);
      FIELD_SET(*this, FIX::HiddenLimitOrderMarginReduction);
      FIELD_SET(*this, FIX::TradingSessionID);
      FIELD_SET(*this, FIX::TradingSessionSubID);
      FIELD_SET(*this, FIX::ExpirationCycle);
      FIELD_SET(*this, FIX::Text);
      FIELD_SET(*this, FIX::EncodedTextLen);
      FIELD_SET(*this, FIX::EncodedText);
      FIELD_SET(*this, FIX::SettlCurrency);
      FIELD_SET(*this, FIX::SettlCurrencyPrecision);
      FIELD_SET(*this, FIX::SettlCurrencySortOrder);
      FIELD_SET(*this, FIX::ColorRef);
      FIELD_SET(*this, FIX::Commission);
      FIELD_SET(*this, FIX::LimitsCommission);
      FIELD_SET(*this, FIX::CommType);
      FIELD_SET(*this, FIX::CommChargeType);
      FIELD_SET(*this, FIX::CommChargeMethod);
      FIELD_SET(*this, FIX::MinCommission);
      FIELD_SET(*this, FIX::MinCommissionCurrency);
      FIELD_SET(*this, FIX::SwapType);
      FIELD_SET(*this, FIX::SwapSizeShort);
      FIELD_SET(*this, FIX::SwapSizeLong);
      FIELD_SET(*this, FIX::TripleSwapDay);
      FIELD_SET(*this, FIX::TradeEnabled);
      FIELD_SET(*this, FIX::DefaultSlippage);
      FIELD_SET(*this, FIX::SortOrder);
      FIELD_SET(*this, FIX::GroupSortOrder);
      FIELD_SET(*this, FIX::StatusGroupID);
      FIELD_SET(*this, FIX::CloseOnly);
      FIELD_SET(*this, FIX::NoUnderlyings);
      class NoUnderlyings: public FIX::Group
      {
      public:
      NoUnderlyings() : FIX::Group(711,311,FIX::message_order(311,312,309,305,457,462,463,310,763,313,542,241,242,243,244,245,246,256,595,592,593,594,247,316,941,317,436,435,308,306,362,363,307,364,365,877,878,318,879,810,882,883,884,885,886,0)) {}
        FIELD_SET(*this, FIX::UnderlyingSymbol);
        FIELD_SET(*this, FIX::UnderlyingSymbolSfx);
        FIELD_SET(*this, FIX::UnderlyingSecurityID);
        FIELD_SET(*this, FIX::UnderlyingSecurityIDSource);
        FIELD_SET(*this, FIX::UnderlyingProduct);
        FIELD_SET(*this, FIX::UnderlyingCFICode);
        FIELD_SET(*this, FIX::UnderlyingSecurityType);
        FIELD_SET(*this, FIX::UnderlyingSecuritySubType);
        FIELD_SET(*this, FIX::UnderlyingMaturityMonthYear);
        FIELD_SET(*this, FIX::UnderlyingMaturityDate);
        FIELD_SET(*this, FIX::UnderlyingCouponPaymentDate);
        FIELD_SET(*this, FIX::UnderlyingIssueDate);
        FIELD_SET(*this, FIX::UnderlyingRepoCollateralSecurityType);
        FIELD_SET(*this, FIX::UnderlyingRepurchaseTerm);
        FIELD_SET(*this, FIX::UnderlyingRepurchaseRate);
        FIELD_SET(*this, FIX::UnderlyingFactor);
        FIELD_SET(*this, FIX::UnderlyingCreditRating);
        FIELD_SET(*this, FIX::UnderlyingInstrRegistry);
        FIELD_SET(*this, FIX::UnderlyingCountryOfIssue);
        FIELD_SET(*this, FIX::UnderlyingStateOrProvinceOfIssue);
        FIELD_SET(*this, FIX::UnderlyingLocaleOfIssue);
        FIELD_SET(*this, FIX::UnderlyingRedemptionDate);
        FIELD_SET(*this, FIX::UnderlyingStrikePrice);
        FIELD_SET(*this, FIX::UnderlyingStrikeCurrency);
        FIELD_SET(*this, FIX::UnderlyingOptAttribute);
        FIELD_SET(*this, FIX::UnderlyingContractMultiplier);
        FIELD_SET(*this, FIX::UnderlyingCouponRate);
        FIELD_SET(*this, FIX::UnderlyingSecurityExchange);
        FIELD_SET(*this, FIX::UnderlyingIssuer);
        FIELD_SET(*this, FIX::EncodedUnderlyingIssuerLen);
        FIELD_SET(*this, FIX::EncodedUnderlyingIssuer);
        FIELD_SET(*this, FIX::UnderlyingSecurityDesc);
        FIELD_SET(*this, FIX::EncodedUnderlyingSecurityDescLen);
        FIELD_SET(*this, FIX::EncodedUnderlyingSecurityDesc);
        FIELD_SET(*this, FIX::UnderlyingCPProgram);
        FIELD_SET(*this, FIX::UnderlyingCPRegType);
        FIELD_SET(*this, FIX::UnderlyingCurrency);
        FIELD_SET(*this, FIX::UnderlyingQty);
        FIELD_SET(*this, FIX::UnderlyingPx);
        FIELD_SET(*this, FIX::UnderlyingDirtyPrice);
        FIELD_SET(*this, FIX::UnderlyingEndPrice);
        FIELD_SET(*this, FIX::UnderlyingStartValue);
        FIELD_SET(*this, FIX::UnderlyingCurrentValue);
        FIELD_SET(*this, FIX::UnderlyingEndValue);
        FIELD_SET(*this, FIX::NoUnderlyingSecurityAltID);
        class NoUnderlyingSecurityAltID: public FIX::Group
        {
        public:
        NoUnderlyingSecurityAltID() : FIX::Group(457,458,FIX::message_order(458,459,0)) {}
          FIELD_SET(*this, FIX::UnderlyingSecurityAltID);
          FIELD_SET(*this, FIX::UnderlyingSecurityAltIDSource);
        };
      };
      FIELD_SET(*this, FIX::NoLegs);
      class NoLegs: public FIX::Group
      {
      public:
      NoLegs() : FIX::Group(555,600,FIX::message_order(600,601,602,603,604,607,608,609,764,610,611,248,249,250,251,252,253,257,599,596,597,598,254,612,942,613,614,615,616,617,618,619,620,621,622,623,624,556,740,739,955,956,690,587,683,676,677,678,679,680,0)) {}
        FIELD_SET(*this, FIX::LegSymbol);
        FIELD_SET(*this, FIX::LegSymbolSfx);
        FIELD_SET(*this, FIX::LegSecurityID);
        FIELD_SET(*this, FIX::LegSecurityIDSource);
        FIELD_SET(*this, FIX::LegProduct);
        FIELD_SET(*this, FIX::LegCFICode);
        FIELD_SET(*this, FIX::LegSecurityType);
        FIELD_SET(*this, FIX::LegSecuritySubType);
        FIELD_SET(*this, FIX::LegMaturityMonthYear);
        FIELD_SET(*this, FIX::LegMaturityDate);
        FIELD_SET(*this, FIX::LegCouponPaymentDate);
        FIELD_SET(*this, FIX::LegIssueDate);
        FIELD_SET(*this, FIX::LegRepoCollateralSecurityType);
        FIELD_SET(*this, FIX::LegRepurchaseTerm);
        FIELD_SET(*this, FIX::LegRepurchaseRate);
        FIELD_SET(*this, FIX::LegFactor);
        FIELD_SET(*this, FIX::LegCreditRating);
        FIELD_SET(*this, FIX::LegInstrRegistry);
        FIELD_SET(*this, FIX::LegCountryOfIssue);
        FIELD_SET(*this, FIX::LegStateOrProvinceOfIssue);
        FIELD_SET(*this, FIX::LegLocaleOfIssue);
        FIELD_SET(*this, FIX::LegRedemptionDate);
        FIELD_SET(*this, FIX::LegStrikePrice);
        FIELD_SET(*this, FIX::LegStrikeCurrency);
        FIELD_SET(*this, FIX::LegOptAttribute);
        FIELD_SET(*this, FIX::LegContractMultiplier);
        FIELD_SET(*this, FIX::LegCouponRate);
        FIELD_SET(*this, FIX::LegSecurityExchange);
        FIELD_SET(*this, FIX::LegIssuer);
        FIELD_SET(*this, FIX::EncodedLegIssuerLen);
        FIELD_SET(*this, FIX::EncodedLegIssuer);
        FIELD_SET(*this, FIX::LegSecurityDesc);
        FIELD_SET(*this, FIX::EncodedLegSecurityDescLen);
        FIELD_SET(*this, FIX::EncodedLegSecurityDesc);
        FIELD_SET(*this, FIX::LegRatioQty);
        FIELD_SET(*this, FIX::LegSide);
        FIELD_SET(*this, FIX::LegCurrency);
        FIELD_SET(*this, FIX::LegPool);
        FIELD_SET(*this, FIX::LegDatedDate);
        FIELD_SET(*this, FIX::LegContractSettlMonth);
        FIELD_SET(*this, FIX::LegInterestAccrualDate);
        FIELD_SET(*this, FIX::NoLegSecurityAltID);
        class NoLegSecurityAltID: public FIX::Group
        {
        public:
        NoLegSecurityAltID() : FIX::Group(604,605,FIX::message_order(605,606,0)) {}
          FIELD_SET(*this, FIX::LegSecurityAltID);
          FIELD_SET(*this, FIX::LegSecurityAltIDSource);
        };
        FIELD_SET(*this, FIX::LegSwapType);
        FIELD_SET(*this, FIX::LegSettlType);
        FIELD_SET(*this, FIX::NoLegStipulations);
        class NoLegStipulations: public FIX::Group
        {
        public:
        NoLegStipulations() : FIX::Group(683,688,FIX::message_order(688,689,0)) {}
          FIELD_SET(*this, FIX::LegStipulationType);
          FIELD_SET(*this, FIX::LegStipulationValue);
        };
        FIELD_SET(*this, FIX::LegBenchmarkCurveCurrency);
        FIELD_SET(*this, FIX::LegBenchmarkCurveName);
        FIELD_SET(*this, FIX::LegBenchmarkCurvePoint);
        FIELD_SET(*this, FIX::LegBenchmarkPrice);
        FIELD_SET(*this, FIX::LegBenchmarkPriceType);
      };
    };
  };

}

#endif
