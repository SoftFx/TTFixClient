/* -*- C++ -*- */
 
/****************************************************************************
** Copyright (c) 2001-2014
**
** This file is part of the QuickFIX FIX Engine
**
** This file may be distributed under the terms of the quickfixengine.org
** license as defined by quickfixengine.org and appearing in the file
** LICENSE included in the packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.quickfixengine.org/LICENSE for licensing information.
**
** Contact ask@quickfixengine.org if any conditions of this licensing are
** not clear to you.
**
****************************************************************************/

#ifndef FIX44_MESSAGECRACKER_H
#define FIX44_MESSAGECRACKER_H


#include "../SessionID.h"
#include "../Exceptions.h"

#include "../fix44/Message.h"

namespace FIX44
{ 
  class Heartbeat;
  class TestRequest;
  class ResendRequest;
  class Reject;
  class SequenceReset;
  class Logout;
  class IOI;
  class Advertisement;
  class ExecutionReport;
  class OrderCancelReject;
  class Logon;
  class News;
  class Email;
  class NewOrderSingle;
  class NewOrderList;
  class OrderCancelRequest;
  class OrderCancelReplaceRequest;
  class OrderStatusRequest;
  class AllocationInstruction;
  class ListCancelRequest;
  class ListExecute;
  class ListStatusRequest;
  class ListStatus;
  class AllocationInstructionAck;
  class DontKnowTrade;
  class QuoteRequest;
  class Quote;
  class SettlementInstructions;
  class MarketDataRequest;
  class MarketDataSnapshotFullRefresh;
  class MarketDataIncrementalRefresh;
  class MarketDataRequestReject;
  class QuoteCancel;
  class QuoteStatusRequest;
  class MassQuoteAcknowledgement;
  class SecurityDefinitionRequest;
  class SecurityDefinition;
  class SecurityStatusRequest;
  class SecurityStatus;
  class TradingSessionStatusRequest;
  class TradingSessionStatus;
  class MassQuote;
  class BusinessMessageReject;
  class BidRequest;
  class BidResponse;
  class ListStrikePrice;
  class RegistrationInstructions;
  class RegistrationInstructionsResponse;
  class OrderMassCancelRequest;
  class OrderMassCancelReport;
  class NewOrderCross;
  class CrossOrderCancelReplaceRequest;
  class CrossOrderCancelRequest;
  class SecurityTypeRequest;
  class SecurityTypes;
  class CurrencyListRequest;
  class CurrencyList;
  class SecurityListRequest;
  class SecurityList;
  class DerivativeSecurityListRequest;
  class DerivativeSecurityList;
  class NewOrderMultileg;
  class MultilegOrderCancelReplace;
  class TradeCaptureReportRequest;
  class TradeCaptureReport;
  class OrderMassStatusRequest;
  class QuoteRequestReject;
  class RFQRequest;
  class QuoteStatusReport;
  class QuoteResponse;
  class Confirmation;
  class PositionMaintenanceRequest;
  class PositionMaintenanceReport;
  class RequestForPositions;
  class RequestForPositionsAck;
  class PositionReport;
  class TradeCaptureReportRequestAck;
  class TradeCaptureReportAck;
  class AllocationReport;
  class AllocationReportAck;
  class ConfirmationAck;
  class SettlementInstructionRequest;
  class AssignmentReport;
  class CollateralRequest;
  class CollateralAssignment;
  class CollateralResponse;
  class CollateralReport;
  class CollateralInquiry;
  class NetworkCounterpartySystemStatusRequest;
  class NetworkCounterpartySystemStatusResponse;
  class UserRequest;
  class UserResponse;
  class CollateralInquiryAck;
  class ConfirmationRequest;
  class ApplicationPing;
  class ApplicationPingReply;
  class OrderTimeoutCurrenex;
  class Initialize;
  class MarketDataHistoryRequest;
  class MarketDataHistoryRequestReject;
  class MarketDataHistory;
  class FileChunk;
  class FileChunkReq;
  class AccountInfoRequest;
  class AccountInfo;
  class ClosePositionRequest;
  class ClosePositionRequestAck;
  class Notification;
  class MarketDataRequestAck;
  class FileChunkReqReject;
  class MarketDataHistoryMetadataRequest;
  class MarketDataHistoryMetadataReport;
  class TradeTransactionReportRequest;
  class TradeTransactionReportRequestAck;
  class TradeTransactionReport;
  class ComponentsInfoRequest;
  class ComponentsInfoReport;
  class TwoFactorLogon;
  class TradeServerInfoRequest;
  class TradeServerInfoReport;
  class DailyAccountSnapshotRequest;
  class DailyAccountSnapshotRequestAck;
  class DailyAccountSnapshotReport;
  class MarketDataHistoryInfoRequest;
  class MarketDataHistoryInfoReport;

  class MessageCracker
  {
  public:
  virtual ~MessageCracker() {}
  virtual void onMessage( const Message&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( Message&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
 virtual void onMessage( const Heartbeat&, const FIX::SessionID& )
    {}
  virtual void onMessage( const TestRequest&, const FIX::SessionID& )
    {}
  virtual void onMessage( const ResendRequest&, const FIX::SessionID& )
    {}
  virtual void onMessage( const Reject&, const FIX::SessionID& )
    {}
  virtual void onMessage( const SequenceReset&, const FIX::SessionID& )
    {}
  virtual void onMessage( const Logout&, const FIX::SessionID& )
    {}
  virtual void onMessage( const IOI&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const Advertisement&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const ExecutionReport&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const OrderCancelReject&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const Logon&, const FIX::SessionID& )
    {}
  virtual void onMessage( const News&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const Email&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const NewOrderSingle&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const NewOrderList&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const OrderCancelRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const OrderCancelReplaceRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const OrderStatusRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const AllocationInstruction&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const ListCancelRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const ListExecute&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const ListStatusRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const ListStatus&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const AllocationInstructionAck&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const DontKnowTrade&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const QuoteRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const Quote&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const SettlementInstructions&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const MarketDataRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const MarketDataSnapshotFullRefresh&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const MarketDataIncrementalRefresh&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const MarketDataRequestReject&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const QuoteCancel&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const QuoteStatusRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const MassQuoteAcknowledgement&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const SecurityDefinitionRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const SecurityDefinition&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const SecurityStatusRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const SecurityStatus&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const TradingSessionStatusRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const TradingSessionStatus&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const MassQuote&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const BusinessMessageReject&, const FIX::SessionID& )
    {}
  virtual void onMessage( const BidRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const BidResponse&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const ListStrikePrice&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const RegistrationInstructions&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const RegistrationInstructionsResponse&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const OrderMassCancelRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const OrderMassCancelReport&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const NewOrderCross&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const CrossOrderCancelReplaceRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const CrossOrderCancelRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const SecurityTypeRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const SecurityTypes&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const CurrencyListRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const CurrencyList&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const SecurityListRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const SecurityList&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const DerivativeSecurityListRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const DerivativeSecurityList&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const NewOrderMultileg&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const MultilegOrderCancelReplace&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const TradeCaptureReportRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const TradeCaptureReport&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const OrderMassStatusRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const QuoteRequestReject&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const RFQRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const QuoteStatusReport&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const QuoteResponse&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const Confirmation&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const PositionMaintenanceRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const PositionMaintenanceReport&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const RequestForPositions&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const RequestForPositionsAck&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const PositionReport&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const TradeCaptureReportRequestAck&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const TradeCaptureReportAck&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const AllocationReport&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const AllocationReportAck&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const ConfirmationAck&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const SettlementInstructionRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const AssignmentReport&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const CollateralRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const CollateralAssignment&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const CollateralResponse&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const CollateralReport&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const CollateralInquiry&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const NetworkCounterpartySystemStatusRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const NetworkCounterpartySystemStatusResponse&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const UserRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const UserResponse&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const CollateralInquiryAck&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const ConfirmationRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const ApplicationPing&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const ApplicationPingReply&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const OrderTimeoutCurrenex&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const Initialize&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const MarketDataHistoryRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const MarketDataHistoryRequestReject&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const MarketDataHistory&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const FileChunk&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const FileChunkReq&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const AccountInfoRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const AccountInfo&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const ClosePositionRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const ClosePositionRequestAck&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const Notification&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const MarketDataRequestAck&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const FileChunkReqReject&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const MarketDataHistoryMetadataRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const MarketDataHistoryMetadataReport&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const TradeTransactionReportRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const TradeTransactionReportRequestAck&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const TradeTransactionReport&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const ComponentsInfoRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const ComponentsInfoReport&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const TwoFactorLogon&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const TradeServerInfoRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const TradeServerInfoReport&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const DailyAccountSnapshotRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const DailyAccountSnapshotRequestAck&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const DailyAccountSnapshotReport&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const MarketDataHistoryInfoRequest&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( const MarketDataHistoryInfoReport&, const FIX::SessionID& )
    { throw FIX::UnsupportedMessageType(); }
  virtual void onMessage( Heartbeat&, const FIX::SessionID& ) {}
 virtual void onMessage( TestRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( ResendRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( Reject&, const FIX::SessionID& ) {}
 virtual void onMessage( SequenceReset&, const FIX::SessionID& ) {}
 virtual void onMessage( Logout&, const FIX::SessionID& ) {}
 virtual void onMessage( IOI&, const FIX::SessionID& ) {}
 virtual void onMessage( Advertisement&, const FIX::SessionID& ) {}
 virtual void onMessage( ExecutionReport&, const FIX::SessionID& ) {}
 virtual void onMessage( OrderCancelReject&, const FIX::SessionID& ) {}
 virtual void onMessage( Logon&, const FIX::SessionID& ) {}
 virtual void onMessage( News&, const FIX::SessionID& ) {}
 virtual void onMessage( Email&, const FIX::SessionID& ) {}
 virtual void onMessage( NewOrderSingle&, const FIX::SessionID& ) {}
 virtual void onMessage( NewOrderList&, const FIX::SessionID& ) {}
 virtual void onMessage( OrderCancelRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( OrderCancelReplaceRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( OrderStatusRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( AllocationInstruction&, const FIX::SessionID& ) {}
 virtual void onMessage( ListCancelRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( ListExecute&, const FIX::SessionID& ) {}
 virtual void onMessage( ListStatusRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( ListStatus&, const FIX::SessionID& ) {}
 virtual void onMessage( AllocationInstructionAck&, const FIX::SessionID& ) {}
 virtual void onMessage( DontKnowTrade&, const FIX::SessionID& ) {}
 virtual void onMessage( QuoteRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( Quote&, const FIX::SessionID& ) {}
 virtual void onMessage( SettlementInstructions&, const FIX::SessionID& ) {}
 virtual void onMessage( MarketDataRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( MarketDataSnapshotFullRefresh&, const FIX::SessionID& ) {}
 virtual void onMessage( MarketDataIncrementalRefresh&, const FIX::SessionID& ) {}
 virtual void onMessage( MarketDataRequestReject&, const FIX::SessionID& ) {}
 virtual void onMessage( QuoteCancel&, const FIX::SessionID& ) {}
 virtual void onMessage( QuoteStatusRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( MassQuoteAcknowledgement&, const FIX::SessionID& ) {}
 virtual void onMessage( SecurityDefinitionRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( SecurityDefinition&, const FIX::SessionID& ) {}
 virtual void onMessage( SecurityStatusRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( SecurityStatus&, const FIX::SessionID& ) {}
 virtual void onMessage( TradingSessionStatusRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( TradingSessionStatus&, const FIX::SessionID& ) {}
 virtual void onMessage( MassQuote&, const FIX::SessionID& ) {}
 virtual void onMessage( BusinessMessageReject&, const FIX::SessionID& ) {}
 virtual void onMessage( BidRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( BidResponse&, const FIX::SessionID& ) {}
 virtual void onMessage( ListStrikePrice&, const FIX::SessionID& ) {}
 virtual void onMessage( RegistrationInstructions&, const FIX::SessionID& ) {}
 virtual void onMessage( RegistrationInstructionsResponse&, const FIX::SessionID& ) {}
 virtual void onMessage( OrderMassCancelRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( OrderMassCancelReport&, const FIX::SessionID& ) {}
 virtual void onMessage( NewOrderCross&, const FIX::SessionID& ) {}
 virtual void onMessage( CrossOrderCancelReplaceRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( CrossOrderCancelRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( SecurityTypeRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( SecurityTypes&, const FIX::SessionID& ) {}
 virtual void onMessage( CurrencyListRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( CurrencyList&, const FIX::SessionID& ) {}
 virtual void onMessage( SecurityListRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( SecurityList&, const FIX::SessionID& ) {}
 virtual void onMessage( DerivativeSecurityListRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( DerivativeSecurityList&, const FIX::SessionID& ) {}
 virtual void onMessage( NewOrderMultileg&, const FIX::SessionID& ) {}
 virtual void onMessage( MultilegOrderCancelReplace&, const FIX::SessionID& ) {}
 virtual void onMessage( TradeCaptureReportRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( TradeCaptureReport&, const FIX::SessionID& ) {}
 virtual void onMessage( OrderMassStatusRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( QuoteRequestReject&, const FIX::SessionID& ) {}
 virtual void onMessage( RFQRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( QuoteStatusReport&, const FIX::SessionID& ) {}
 virtual void onMessage( QuoteResponse&, const FIX::SessionID& ) {}
 virtual void onMessage( Confirmation&, const FIX::SessionID& ) {}
 virtual void onMessage( PositionMaintenanceRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( PositionMaintenanceReport&, const FIX::SessionID& ) {}
 virtual void onMessage( RequestForPositions&, const FIX::SessionID& ) {}
 virtual void onMessage( RequestForPositionsAck&, const FIX::SessionID& ) {}
 virtual void onMessage( PositionReport&, const FIX::SessionID& ) {}
 virtual void onMessage( TradeCaptureReportRequestAck&, const FIX::SessionID& ) {}
 virtual void onMessage( TradeCaptureReportAck&, const FIX::SessionID& ) {}
 virtual void onMessage( AllocationReport&, const FIX::SessionID& ) {}
 virtual void onMessage( AllocationReportAck&, const FIX::SessionID& ) {}
 virtual void onMessage( ConfirmationAck&, const FIX::SessionID& ) {}
 virtual void onMessage( SettlementInstructionRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( AssignmentReport&, const FIX::SessionID& ) {}
 virtual void onMessage( CollateralRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( CollateralAssignment&, const FIX::SessionID& ) {}
 virtual void onMessage( CollateralResponse&, const FIX::SessionID& ) {}
 virtual void onMessage( CollateralReport&, const FIX::SessionID& ) {}
 virtual void onMessage( CollateralInquiry&, const FIX::SessionID& ) {}
 virtual void onMessage( NetworkCounterpartySystemStatusRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( NetworkCounterpartySystemStatusResponse&, const FIX::SessionID& ) {}
 virtual void onMessage( UserRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( UserResponse&, const FIX::SessionID& ) {}
 virtual void onMessage( CollateralInquiryAck&, const FIX::SessionID& ) {}
 virtual void onMessage( ConfirmationRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( ApplicationPing&, const FIX::SessionID& ) {}
 virtual void onMessage( ApplicationPingReply&, const FIX::SessionID& ) {}
 virtual void onMessage( OrderTimeoutCurrenex&, const FIX::SessionID& ) {}
 virtual void onMessage( Initialize&, const FIX::SessionID& ) {}
 virtual void onMessage( MarketDataHistoryRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( MarketDataHistoryRequestReject&, const FIX::SessionID& ) {}
 virtual void onMessage( MarketDataHistory&, const FIX::SessionID& ) {}
 virtual void onMessage( FileChunk&, const FIX::SessionID& ) {}
 virtual void onMessage( FileChunkReq&, const FIX::SessionID& ) {}
 virtual void onMessage( AccountInfoRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( AccountInfo&, const FIX::SessionID& ) {}
 virtual void onMessage( ClosePositionRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( ClosePositionRequestAck&, const FIX::SessionID& ) {}
 virtual void onMessage( Notification&, const FIX::SessionID& ) {}
 virtual void onMessage( MarketDataRequestAck&, const FIX::SessionID& ) {}
 virtual void onMessage( FileChunkReqReject&, const FIX::SessionID& ) {}
 virtual void onMessage( MarketDataHistoryMetadataRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( MarketDataHistoryMetadataReport&, const FIX::SessionID& ) {}
 virtual void onMessage( TradeTransactionReportRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( TradeTransactionReportRequestAck&, const FIX::SessionID& ) {}
 virtual void onMessage( TradeTransactionReport&, const FIX::SessionID& ) {}
 virtual void onMessage( ComponentsInfoRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( ComponentsInfoReport&, const FIX::SessionID& ) {}
 virtual void onMessage( TwoFactorLogon&, const FIX::SessionID& ) {}
 virtual void onMessage( TradeServerInfoRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( TradeServerInfoReport&, const FIX::SessionID& ) {}
 virtual void onMessage( DailyAccountSnapshotRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( DailyAccountSnapshotRequestAck&, const FIX::SessionID& ) {}
 virtual void onMessage( DailyAccountSnapshotReport&, const FIX::SessionID& ) {}
 virtual void onMessage( MarketDataHistoryInfoRequest&, const FIX::SessionID& ) {}
 virtual void onMessage( MarketDataHistoryInfoReport&, const FIX::SessionID& ) {}

public:
  void crack( const Message& message,
              const FIX::SessionID& sessionID )
  {
    const std::string& msgTypeValue
      = message.getHeader().getField( FIX::FIELD::MsgType );

    
    if( msgTypeValue == "0" )
    {
      onMessage( (const Heartbeat&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "1" )
    {
      onMessage( (const TestRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "2" )
    {
      onMessage( (const ResendRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "3" )
    {
      onMessage( (const Reject&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "4" )
    {
      onMessage( (const SequenceReset&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "5" )
    {
      onMessage( (const Logout&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "6" )
    {
      onMessage( (const IOI&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "7" )
    {
      onMessage( (const Advertisement&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "8" )
    {
      onMessage( (const ExecutionReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "9" )
    {
      onMessage( (const OrderCancelReject&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "A" )
    {
      onMessage( (const Logon&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "B" )
    {
      onMessage( (const News&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "C" )
    {
      onMessage( (const Email&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "D" )
    {
      onMessage( (const NewOrderSingle&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "E" )
    {
      onMessage( (const NewOrderList&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "F" )
    {
      onMessage( (const OrderCancelRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "G" )
    {
      onMessage( (const OrderCancelReplaceRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "H" )
    {
      onMessage( (const OrderStatusRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "J" )
    {
      onMessage( (const AllocationInstruction&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "K" )
    {
      onMessage( (const ListCancelRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "L" )
    {
      onMessage( (const ListExecute&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "M" )
    {
      onMessage( (const ListStatusRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "N" )
    {
      onMessage( (const ListStatus&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "P" )
    {
      onMessage( (const AllocationInstructionAck&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "Q" )
    {
      onMessage( (const DontKnowTrade&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "R" )
    {
      onMessage( (const QuoteRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "S" )
    {
      onMessage( (const Quote&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "T" )
    {
      onMessage( (const SettlementInstructions&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "V" )
    {
      onMessage( (const MarketDataRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "W" )
    {
      onMessage( (const MarketDataSnapshotFullRefresh&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "X" )
    {
      onMessage( (const MarketDataIncrementalRefresh&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "Y" )
    {
      onMessage( (const MarketDataRequestReject&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "Z" )
    {
      onMessage( (const QuoteCancel&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "a" )
    {
      onMessage( (const QuoteStatusRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "b" )
    {
      onMessage( (const MassQuoteAcknowledgement&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "c" )
    {
      onMessage( (const SecurityDefinitionRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "d" )
    {
      onMessage( (const SecurityDefinition&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "e" )
    {
      onMessage( (const SecurityStatusRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "f" )
    {
      onMessage( (const SecurityStatus&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "g" )
    {
      onMessage( (const TradingSessionStatusRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "h" )
    {
      onMessage( (const TradingSessionStatus&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "i" )
    {
      onMessage( (const MassQuote&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "j" )
    {
      onMessage( (const BusinessMessageReject&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "k" )
    {
      onMessage( (const BidRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "l" )
    {
      onMessage( (const BidResponse&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "m" )
    {
      onMessage( (const ListStrikePrice&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "o" )
    {
      onMessage( (const RegistrationInstructions&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "p" )
    {
      onMessage( (const RegistrationInstructionsResponse&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "q" )
    {
      onMessage( (const OrderMassCancelRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "r" )
    {
      onMessage( (const OrderMassCancelReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "s" )
    {
      onMessage( (const NewOrderCross&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "t" )
    {
      onMessage( (const CrossOrderCancelReplaceRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "u" )
    {
      onMessage( (const CrossOrderCancelRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "v" )
    {
      onMessage( (const SecurityTypeRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "w" )
    {
      onMessage( (const SecurityTypes&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1020" )
    {
      onMessage( (const CurrencyListRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1021" )
    {
      onMessage( (const CurrencyList&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "x" )
    {
      onMessage( (const SecurityListRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "y" )
    {
      onMessage( (const SecurityList&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "z" )
    {
      onMessage( (const DerivativeSecurityListRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AA" )
    {
      onMessage( (const DerivativeSecurityList&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AB" )
    {
      onMessage( (const NewOrderMultileg&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AC" )
    {
      onMessage( (const MultilegOrderCancelReplace&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AD" )
    {
      onMessage( (const TradeCaptureReportRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AE" )
    {
      onMessage( (const TradeCaptureReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AF" )
    {
      onMessage( (const OrderMassStatusRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AG" )
    {
      onMessage( (const QuoteRequestReject&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AH" )
    {
      onMessage( (const RFQRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AI" )
    {
      onMessage( (const QuoteStatusReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AJ" )
    {
      onMessage( (const QuoteResponse&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AK" )
    {
      onMessage( (const Confirmation&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AL" )
    {
      onMessage( (const PositionMaintenanceRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AM" )
    {
      onMessage( (const PositionMaintenanceReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AN" )
    {
      onMessage( (const RequestForPositions&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AO" )
    {
      onMessage( (const RequestForPositionsAck&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AP" )
    {
      onMessage( (const PositionReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AQ" )
    {
      onMessage( (const TradeCaptureReportRequestAck&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AR" )
    {
      onMessage( (const TradeCaptureReportAck&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AS" )
    {
      onMessage( (const AllocationReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AT" )
    {
      onMessage( (const AllocationReportAck&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AU" )
    {
      onMessage( (const ConfirmationAck&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AV" )
    {
      onMessage( (const SettlementInstructionRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AW" )
    {
      onMessage( (const AssignmentReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AX" )
    {
      onMessage( (const CollateralRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AY" )
    {
      onMessage( (const CollateralAssignment&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AZ" )
    {
      onMessage( (const CollateralResponse&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "BA" )
    {
      onMessage( (const CollateralReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "BB" )
    {
      onMessage( (const CollateralInquiry&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "BC" )
    {
      onMessage( (const NetworkCounterpartySystemStatusRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "BD" )
    {
      onMessage( (const NetworkCounterpartySystemStatusResponse&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "BE" )
    {
      onMessage( (const UserRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "BF" )
    {
      onMessage( (const UserResponse&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "BG" )
    {
      onMessage( (const CollateralInquiryAck&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "BH" )
    {
      onMessage( (const ConfirmationRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1" )
    {
      onMessage( (const ApplicationPing&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U2" )
    {
      onMessage( (const ApplicationPingReply&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U3" )
    {
      onMessage( (const OrderTimeoutCurrenex&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U4" )
    {
      onMessage( (const Initialize&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1000" )
    {
      onMessage( (const MarketDataHistoryRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1001" )
    {
      onMessage( (const MarketDataHistoryRequestReject&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1002" )
    {
      onMessage( (const MarketDataHistory&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1003" )
    {
      onMessage( (const FileChunk&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1004" )
    {
      onMessage( (const FileChunkReq&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1005" )
    {
      onMessage( (const AccountInfoRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1006" )
    {
      onMessage( (const AccountInfo&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1008" )
    {
      onMessage( (const ClosePositionRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1009" )
    {
      onMessage( (const ClosePositionRequestAck&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1010" )
    {
      onMessage( (const Notification&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1011" )
    {
      onMessage( (const MarketDataRequestAck&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1012" )
    {
      onMessage( (const FileChunkReqReject&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1013" )
    {
      onMessage( (const MarketDataHistoryMetadataRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1014" )
    {
      onMessage( (const MarketDataHistoryMetadataReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1015" )
    {
      onMessage( (const TradeTransactionReportRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1016" )
    {
      onMessage( (const TradeTransactionReportRequestAck&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1017" )
    {
      onMessage( (const TradeTransactionReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1018" )
    {
      onMessage( (const ComponentsInfoRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1019" )
    {
      onMessage( (const ComponentsInfoReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1022" )
    {
      onMessage( (const TwoFactorLogon&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1023" )
    {
      onMessage( (const TradeServerInfoRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1024" )
    {
      onMessage( (const TradeServerInfoReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1025" )
    {
      onMessage( (const DailyAccountSnapshotRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1026" )
    {
      onMessage( (const DailyAccountSnapshotRequestAck&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1027" )
    {
      onMessage( (const DailyAccountSnapshotReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1028" )
    {
      onMessage( (const MarketDataHistoryInfoRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1029" )
    {
      onMessage( (const MarketDataHistoryInfoReport&)message, sessionID );
      return;
    }
    
    onMessage( message, sessionID );
  }

void crack( Message& message,
            const FIX::SessionID& sessionID )
  {
    FIX::MsgType msgType;
    message.getHeader().getField(msgType);
    std::string msgTypeValue = msgType.getValue();

    
    if( msgTypeValue == "0" )
    {
      onMessage( (Heartbeat&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "1" )
    {
      onMessage( (TestRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "2" )
    {
      onMessage( (ResendRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "3" )
    {
      onMessage( (Reject&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "4" )
    {
      onMessage( (SequenceReset&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "5" )
    {
      onMessage( (Logout&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "6" )
    {
      onMessage( (IOI&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "7" )
    {
      onMessage( (Advertisement&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "8" )
    {
      onMessage( (ExecutionReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "9" )
    {
      onMessage( (OrderCancelReject&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "A" )
    {
      onMessage( (Logon&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "B" )
    {
      onMessage( (News&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "C" )
    {
      onMessage( (Email&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "D" )
    {
      onMessage( (NewOrderSingle&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "E" )
    {
      onMessage( (NewOrderList&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "F" )
    {
      onMessage( (OrderCancelRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "G" )
    {
      onMessage( (OrderCancelReplaceRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "H" )
    {
      onMessage( (OrderStatusRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "J" )
    {
      onMessage( (AllocationInstruction&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "K" )
    {
      onMessage( (ListCancelRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "L" )
    {
      onMessage( (ListExecute&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "M" )
    {
      onMessage( (ListStatusRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "N" )
    {
      onMessage( (ListStatus&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "P" )
    {
      onMessage( (AllocationInstructionAck&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "Q" )
    {
      onMessage( (DontKnowTrade&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "R" )
    {
      onMessage( (QuoteRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "S" )
    {
      onMessage( (Quote&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "T" )
    {
      onMessage( (SettlementInstructions&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "V" )
    {
      onMessage( (MarketDataRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "W" )
    {
      onMessage( (MarketDataSnapshotFullRefresh&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "X" )
    {
      onMessage( (MarketDataIncrementalRefresh&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "Y" )
    {
      onMessage( (MarketDataRequestReject&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "Z" )
    {
      onMessage( (QuoteCancel&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "a" )
    {
      onMessage( (QuoteStatusRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "b" )
    {
      onMessage( (MassQuoteAcknowledgement&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "c" )
    {
      onMessage( (SecurityDefinitionRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "d" )
    {
      onMessage( (SecurityDefinition&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "e" )
    {
      onMessage( (SecurityStatusRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "f" )
    {
      onMessage( (SecurityStatus&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "g" )
    {
      onMessage( (TradingSessionStatusRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "h" )
    {
      onMessage( (TradingSessionStatus&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "i" )
    {
      onMessage( (MassQuote&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "j" )
    {
      onMessage( (BusinessMessageReject&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "k" )
    {
      onMessage( (BidRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "l" )
    {
      onMessage( (BidResponse&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "m" )
    {
      onMessage( (ListStrikePrice&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "o" )
    {
      onMessage( (RegistrationInstructions&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "p" )
    {
      onMessage( (RegistrationInstructionsResponse&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "q" )
    {
      onMessage( (OrderMassCancelRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "r" )
    {
      onMessage( (OrderMassCancelReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "s" )
    {
      onMessage( (NewOrderCross&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "t" )
    {
      onMessage( (CrossOrderCancelReplaceRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "u" )
    {
      onMessage( (CrossOrderCancelRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "v" )
    {
      onMessage( (SecurityTypeRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "w" )
    {
      onMessage( (SecurityTypes&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1020" )
    {
      onMessage( (CurrencyListRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1021" )
    {
      onMessage( (CurrencyList&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "x" )
    {
      onMessage( (SecurityListRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "y" )
    {
      onMessage( (SecurityList&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "z" )
    {
      onMessage( (DerivativeSecurityListRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AA" )
    {
      onMessage( (DerivativeSecurityList&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AB" )
    {
      onMessage( (NewOrderMultileg&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AC" )
    {
      onMessage( (MultilegOrderCancelReplace&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AD" )
    {
      onMessage( (TradeCaptureReportRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AE" )
    {
      onMessage( (TradeCaptureReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AF" )
    {
      onMessage( (OrderMassStatusRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AG" )
    {
      onMessage( (QuoteRequestReject&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AH" )
    {
      onMessage( (RFQRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AI" )
    {
      onMessage( (QuoteStatusReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AJ" )
    {
      onMessage( (QuoteResponse&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AK" )
    {
      onMessage( (Confirmation&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AL" )
    {
      onMessage( (PositionMaintenanceRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AM" )
    {
      onMessage( (PositionMaintenanceReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AN" )
    {
      onMessage( (RequestForPositions&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AO" )
    {
      onMessage( (RequestForPositionsAck&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AP" )
    {
      onMessage( (PositionReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AQ" )
    {
      onMessage( (TradeCaptureReportRequestAck&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AR" )
    {
      onMessage( (TradeCaptureReportAck&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AS" )
    {
      onMessage( (AllocationReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AT" )
    {
      onMessage( (AllocationReportAck&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AU" )
    {
      onMessage( (ConfirmationAck&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AV" )
    {
      onMessage( (SettlementInstructionRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AW" )
    {
      onMessage( (AssignmentReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AX" )
    {
      onMessage( (CollateralRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AY" )
    {
      onMessage( (CollateralAssignment&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "AZ" )
    {
      onMessage( (CollateralResponse&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "BA" )
    {
      onMessage( (CollateralReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "BB" )
    {
      onMessage( (CollateralInquiry&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "BC" )
    {
      onMessage( (NetworkCounterpartySystemStatusRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "BD" )
    {
      onMessage( (NetworkCounterpartySystemStatusResponse&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "BE" )
    {
      onMessage( (UserRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "BF" )
    {
      onMessage( (UserResponse&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "BG" )
    {
      onMessage( (CollateralInquiryAck&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "BH" )
    {
      onMessage( (ConfirmationRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1" )
    {
      onMessage( (ApplicationPing&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U2" )
    {
      onMessage( (ApplicationPingReply&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U3" )
    {
      onMessage( (OrderTimeoutCurrenex&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U4" )
    {
      onMessage( (Initialize&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1000" )
    {
      onMessage( (MarketDataHistoryRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1001" )
    {
      onMessage( (MarketDataHistoryRequestReject&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1002" )
    {
      onMessage( (MarketDataHistory&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1003" )
    {
      onMessage( (FileChunk&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1004" )
    {
      onMessage( (FileChunkReq&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1005" )
    {
      onMessage( (AccountInfoRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1006" )
    {
      onMessage( (AccountInfo&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1008" )
    {
      onMessage( (ClosePositionRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1009" )
    {
      onMessage( (ClosePositionRequestAck&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1010" )
    {
      onMessage( (Notification&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1011" )
    {
      onMessage( (MarketDataRequestAck&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1012" )
    {
      onMessage( (FileChunkReqReject&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1013" )
    {
      onMessage( (MarketDataHistoryMetadataRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1014" )
    {
      onMessage( (MarketDataHistoryMetadataReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1015" )
    {
      onMessage( (TradeTransactionReportRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1016" )
    {
      onMessage( (TradeTransactionReportRequestAck&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1017" )
    {
      onMessage( (TradeTransactionReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1018" )
    {
      onMessage( (ComponentsInfoRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1019" )
    {
      onMessage( (ComponentsInfoReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1022" )
    {
      onMessage( (TwoFactorLogon&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1023" )
    {
      onMessage( (TradeServerInfoRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1024" )
    {
      onMessage( (TradeServerInfoReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1025" )
    {
      onMessage( (DailyAccountSnapshotRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1026" )
    {
      onMessage( (DailyAccountSnapshotRequestAck&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1027" )
    {
      onMessage( (DailyAccountSnapshotReport&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1028" )
    {
      onMessage( (MarketDataHistoryInfoRequest&)message, sessionID );
      return;
    }
    
    if( msgTypeValue == "U1029" )
    {
      onMessage( (MarketDataHistoryInfoReport&)message, sessionID );
      return;
    }
    
    onMessage( message, sessionID );
  }

  };
}

#endif
