#include <clap/clap.h>
#include "FactoryImpl.h"


extern "C"
{

CLAP_EXPORT const clap_plugin_entry clap_entry =
{
    .clap_version = CLAP_VERSION,
    .init = impl::init,
    .deinit = impl::deinit,
    .get_factory = impl::getFactory
};

}
