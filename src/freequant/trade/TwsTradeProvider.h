#ifndef FQ_TRADE_IBTRADEPROVIDER_H
#define FQ_TRADE_IBTRADEPROVIDER_H

#include <memory>
#include <string>
#include <vector>

#include <freequant/trade/TradeProvider.h>

namespace FreeQuant {
namespace Detail {
class TwsProviderImpl;
}

class TwsTradeProvider : public TradeProvider {
public:
    TwsTradeProvider(const std::string& connection, FreeQuant::TradeProvider::Callback *callback = 0);
    TwsTradeProvider(FreeQuant::TradeProvider::Callback *callback = 0);
    virtual ~TwsTradeProvider();
    void connect();
    void connect(const std::string& connection, bool block = false);
    void disconnect();
    bool isConnected() const;
    std::string name() const { return "TWS"; }

    std::vector<std::string> availableExchanges() const {
        return std::vector<std::string>();
    }
    std::vector<std::string> availableInstruments() const {
        return std::vector<std::string>();
    }
    std::vector<std::string> availableAccounts() const;

    void updateAccounts();

    void logon() {}
    void logout() {}

    void subscribe(std::vector<std::string> symbols);
    void unsubscribe(std::vector<std::string> symbols) {}

    void sendOrder(FreeQuant::Order& order);
    void cancelOrder(FreeQuant::Order& order);
    void replaceOrder(FreeQuant::Order& order);

    void updateIntrument(std::string symbol, bool block = false);
    void updateIntrument(FreeQuant::Instrument& instrument);


    bool orderTypeSupported(FreeQuant::Order::Type type) { return true; }
private:
//    class Impl;
//    Impl *_impl;

    std::unique_ptr<FreeQuant::Detail::TwsProviderImpl> _impl;
};

}  // namespace FreeQuant

#endif // FQ_TRADE_IBTRADEPROVIDER_H

