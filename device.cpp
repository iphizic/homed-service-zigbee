#include "device.h"

Cluster EndPointObject::cluster(quint16 clusterId)
{
    auto it = m_clusters.find(clusterId);

    if (it == m_clusters.end())
        it = m_clusters.insert(clusterId, Cluster(new ClusterObject));

    return it.value();
}

void DeviceObject::setProperties(void)
{
    if (m_vendor == "eWeLink")
    {
        if (m_model == "TH01")
        {
            m_properties = {Property(new Properties::Temperature), Property(new Properties::Humidity)};
            m_reportings = {Reporting(new Reportings::Temperature), Reporting(new Reportings::Humidity)};
            return;
        }
    }
    else if (m_vendor == "IKEA of Sweden")
    {
        if (m_model == "TRADFRI bulb E14 WS 470lm")
        {
            m_actions = {Action(new Actions::Status), Action(new Actions::Level), Action(new Actions::ColorTemperature)};
            m_properties = {Property(new Properties::Status), Property(new Properties::Level), Property(new Properties::ColorTemperature)};
            m_reportings = {Reporting(new Reportings::Status), Reporting(new Reportings::Level), Reporting(new Reportings::ColorTemperature)};
            return;
        }

        if (m_model == "TRADFRIbulbE14WWclear250lm" || m_model == "TRADFRIbulbE27WWclear250lm" || m_model == "TRADFRI bulb E27 W opal 1000lm")
        {
            m_actions = {Action(new Actions::Status), Action(new Actions::Level)};
            m_properties = {Property(new Properties::Status), Property(new Properties::Level)};
            m_reportings = {Reporting(new Reportings::Status), Reporting(new Reportings::Level)};
            return;
        }
    }
    else if (m_vendor == "LUMI")
    {
        if (m_model == "lumi.sens" || m_model == "lumi.sensor_ht")
        {
            m_properties = {Property(new Properties::Temperature), Property(new Properties::Humidity)};
            return;
        }

        if (m_model == "lumi.sensor_motion")
        {
            m_properties = {Property(new Properties::Occupancy)};
            return;
        }
    }
    else if (m_vendor == "XIAOMI")
    {
        if (m_model == "lumi.sen_ill.mgl01")
        {
            m_properties = {Property(new Properties::Illuminance)};
            m_reportings = {Reporting(new Reportings::Illuminance)};
            return;
        }
    }
}
