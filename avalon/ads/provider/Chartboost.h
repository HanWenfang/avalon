#ifndef AVALON_ADS_PROVIDER_CHARTBOOST_H
#define AVALON_ADS_PROVIDER_CHARTBOOST_H

#include <string>
#include <avalon/ads/Provider.h>
#include <avalon/ads/Fullscreen.h>
#include <avalon/ads/Link.h>
#include <external/chartboost/Chartboost-x/ChartboostX.h>

namespace avalon {
namespace ads {
namespace provider {

class Chartboost
: public ChartboostXDelegate
, public Fullscreen
, public Provider
, public Link
{
public:
    int weight;
    std::string appId;
    std::string appSignature;

    Chartboost();

    // Provider
    virtual void init();
    virtual void hideAds();
    virtual int getWeight();

    // Fullscreen
    virtual void showFullscreenAd();

    // Link
    virtual void openAdLink();

    // ChartboostXDelegate method
    virtual bool shouldDisplayInterstitial(const char* location);
    virtual void didCacheInterstitial(const char* location);
    virtual void didFailToLoadInterstitial(const char* location);
    virtual void didCloseInterstitial(const char* location);
    virtual void didClickInterstitial(const char* location);
};

} // namespace provider
} // namespace ads
} // namespace avalon

#endif /* AVALON_ADS_PROVIDER_CHARTBOOST_H */