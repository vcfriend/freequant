#ifndef FQ_TRADE_IBTRADEPROVIDER_H
#define FQ_TRADE_IBTRADEPROVIDER_H

#include <string>
#include <vector>

#include <freequant/trade/TradeProvider.h>

namespace FreeQuant {

class IbTradeProvider : public TradeProvider {
public:
    IbTradeProvider(FreeQuant::TradeProvider::Callback *callback = 0);
    virtual ~IbTradeProvider();
    void connect();
    void disconnect();
    bool isConnected() const;
    std::string name() const { return "IB"; }

    std::vector<std::string> availableExchanges() const {}
    std::vector<std::string> availableInstruments() const {}
    std::vector<std::string> availableAccounts() const;

    void updateAccounts();

    void logon() {}
    void logout() {}

    void subscribe(std::vector<std::string> symbols) {}
    void unsubscribe(std::vector<std::string> symbols) {}

    void sendOrder(FreeQuant::Order& order);
    void cancelOrder(FreeQuant::Order& order);
    void replaceOrder(FreeQuant::Order& order);
private:
    class Impl;
    Impl *_impl;
};


}  // namespace FreeQuant

#endif // FQ_TRADE_IBTRADEPROVIDER_H

