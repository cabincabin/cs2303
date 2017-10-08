/*
 * Orginism.h
 *
 *  Created on: Oct 8, 2017
 *      Author: student
 */

#ifndef ORGINISM_H_
#define ORGINISM_H_

class Orginism {
protected:

public:
	Orginism();
	bool isPrey();
	virtual Orginism* breed();
	virtual ~Orginism();

};

#endif /* ORGINISM_H_ */
