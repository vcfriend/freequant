#ifndef FQ_STRATEGY_INSTRUMENT_H
#define FQ_STRATEGY_INSTRUMENT_H

#include <string>

#include <freequant/utils/DateTime.h>

namespace FreeQuant {

class Currency;

class Instrument {
public:
    enum Type {
        Stock,
        Future,
        Option,
        FutureOption,
        Bond,
        Index,
        ETF,
        Forex,
        MultiLeg
    };

    explicit Instrument(std::string symbol, Instrument::Type type = Instrument::Stock);
    virtual ~Instrument() {}
    void setExchange(std::string exchange) {
        _exchange = exchange;
    }
    std::string exchange() const { return _exchange; }

    void setName(std::string name) { _name = name; }
    std::string name() const { return _name; }

    void setExpireDate(FreeQuant::DateTime dt) {
        _expireDate = dt;
    }
    FreeQuant::DateTime expireDate() const { return _expireDate; }

    double multipler() const { return _multiplier; }
    void setMultipler(double multiplier) { _multiplier = multiplier; }
    double tickSize() const { return _tickSize; }
    void setTickSize(double tickSize) { _tickSize = tickSize; }

    double margin() const { return _margin; }
    void setMargin(double margin) { _margin = margin; }

    std::string symbol() const { return _symbol; }
    Type type() const { return _type; }
    void setType(Instrument::Type type) {  _type = type; }

    void setMinTradeVolume(int value) { _minTradeVolume = value; }
    int minTradeVolume() const { return _minTradeVolume; }

    double factor() const;
    std::string description() const;
    FreeQuant::DateTime maturity() const;

private:
    std::string _symbol;
    std::string _exchange;
    std::string _name;
    FreeQuant::DateTime _expireDate;
    double _multiplier;
    double _tickSize;
    double _margin;
    Type _type;
	Currency *mCurrency;

    int _minTradeVolume;

};

} // namespace FreeQuant

#endif /* FQ_STRATEGY_INSTRUMENT_H */