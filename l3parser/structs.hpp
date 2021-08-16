#pragma once

#include "serializer.h"

#define MD_LEVELS 10
#define LIQ_LEVELS 3

struct BookUpdate {
  BookUpdate() {}

  int32_t                                 _side{0};
  int32_t                                 _update_type{0};
  double                                  _px{0.0};
  double                                  _qty{0.0};
  int64_t                                 _local_time;
};

struct TradeUpdate {
  TradeUpdate() {}

  int32_t                                 _side{0};
  int32_t                                 _tick_type{0};
  int32_t                                 _liquidation_type{0};
  double                                  _px{0.0};
  double                                  _qty{0.0};
  int64_t                                 _timestamp;
  int64_t                                 _local_time;
};

struct FundingUpdate {
  FundingUpdate() {}

  double                                  _rate{0.0};
  int64_t                                 _timestamp;
  int64_t                                 _local_time;
};

struct LiquidationEntry {
  LiquidationEntry() {}
  LiquidationEntry(int side, double px, double qty) :
                   _side(side), _px(px), _qty(qty) {}

  int32_t                                 _side{0};
  double                                  _px{0.0};
  double                                  _qty{0.0};                            
};

struct L2Book {

  std::array<double, MD_LEVELS>           _bp = {0};
  std::array<double, MD_LEVELS>           _bz = {0};
  std::array<double, MD_LEVELS>           _ap = {0};
  std::array<double, MD_LEVELS>           _az = {0};
  int64_t                                 _local_time;
};

struct LiquidationBook {

  std::array<double, LIQ_LEVELS>          _bp = {0};
  std::array<double, LIQ_LEVELS>          _bz = {0};
  std::array<double, LIQ_LEVELS>          _ap = {0};
  std::array<double, LIQ_LEVELS>          _az = {0};
  int64_t                                 _local_time;
};

struct PriceUpdate {
  PriceUpdate() {}

  double                                  _settlement_price{0.0};
  double                                  _mark_price{0.0};
  double                                  _index_price{0.0};
  double                                  _rate{0.0};
  int64_t                                 _timestamp;
  int64_t                                 _local_time;
};