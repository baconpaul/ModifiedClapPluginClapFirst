#pragma once
#include <clap/helpers/plugin.hh>


class Plugin : public clap::helpers::Plugin<clap::helpers::MisbehaviourHandler::Terminate,
                                            clap::helpers::CheckingLevel::Maximal>
{
public:
    static constexpr const char* features[4] =
    {
        CLAP_PLUGIN_FEATURE_AUDIO_EFFECT,
        CLAP_PLUGIN_FEATURE_UTILITY,
        CLAP_PLUGIN_FEATURE_STEREO,
        nullptr
    };

    static constexpr clap_plugin_descriptor descriptor =
    {
        .clap_version = CLAP_VERSION,
        .id = "your.reversed.domain.name.PluginName",
        .name = "Name of the plugin",
        .vendor = "You/your company name",
        .url = "https://your.website",
        .manual_url = "",
        .support_url = "",
        .version = "1.0.0",
        .description = "A short description of your plugin",
        .features = features
    };


    Plugin(const clap_host* host);
    ~Plugin() override = default;


    bool implementsAudioPorts() const noexcept override
    {
        return true;
    }

    uint32_t audioPortsCount(bool /*isInput*/) const noexcept override
    {
        return 1;
    }

    bool audioPortsInfo(uint32_t index, bool isInput, clap_audio_port_info* info) const noexcept override;


    bool implementsParams() const noexcept override
    {
        return true;
    }

    bool isValidParamId(clap_id paramId) const noexcept override
    {
        return paramId == gainPrmId_;
    }

    uint32_t paramsCount() const noexcept override
    {
        return 1;
    }

    bool paramsInfo(uint32_t paramIndex, clap_param_info* info) const noexcept override;

    bool paramsValue(clap_id paramId, double* value) noexcept override;

    bool paramsValueToText(clap_id paramId, double value, char* display, uint32_t size) noexcept override;
    bool paramsTextToValue(clap_id paramId, const char* display, double* value) noexcept override;

    bool activate(double sampleRate, uint32_t, uint32_t) noexcept override;

    clap_process_status process(const clap_process* process) noexcept override;


private:
    static constexpr clap_id gainPrmId_ = 2345;

    double gain_ = 0.0;
    double targetGain_ = 0.0;
    double stepSizeToTargetGain_ = 0.0;
    int fadeLengthInSamples_ = 0;
    int currentFadeIndex_ = fadeLengthInSamples_;
};
