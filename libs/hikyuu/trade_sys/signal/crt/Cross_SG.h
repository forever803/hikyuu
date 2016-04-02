/*
 * CROSS_SG.h
 *
 *  Created on: 2015年2月20日
 *      Author: Administrator
 */

#ifndef TRADE_SYS_SIGNAL_CRT_CROSS_SG_H_
#define TRADE_SYS_SIGNAL_CRT_CROSS_SG_H_

#include "../../../indicator/Operand.h"
#include "../SignalBase.h"

namespace hku {

//SignalPtr HKU_API Cross_SG(const Indicator& fast, const Indicator& slow,
//        const string& kpart = "CLOSE");

SignalPtr HKU_API Cross_SG(const Operand& fast, const Operand& slow);

} /* namespace hku */

#endif /* TRADE_SYS_SIGNAL_CRT_CROSS_SG_H_ */
