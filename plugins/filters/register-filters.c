#include <blosc-private.h>
#include "register-filters.h"
#include "ndmean/ndmean.h"
#include "ndcell/ndcell.h"

void register_filters() {

    blosc2_filter ndcell;
    ndcell.id = BLOSC_FILTER_NDCELL;
    ndcell.forward = (blosc2_filter_forward_cb) ndcell_encoder;
    ndcell.backward = (blosc2_filter_backward_cb) ndcell_decoder;
    register_filter_private(&ndcell);

    blosc2_filter ndmean;
    ndmean.id = BLOSC_FILTER_NDMEAN;
    ndmean.forward = (blosc2_filter_forward_cb) ndmean_encoder;
    ndmean.backward = (blosc2_filter_backward_cb) ndmean_decoder;
    register_filter_private(&ndmean);

}