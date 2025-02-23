//
// Created by Paul Walker on 2/23/25.
//

#ifndef FACTORYIMPL_H
#define FACTORYIMPL_H

namespace impl
{
bool init(const char *);
void deinit();
const void* getFactory(const char* /*factory_id*/);
}
#endif //FACTORYIMPL_H
