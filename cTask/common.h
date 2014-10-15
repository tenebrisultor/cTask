/* 
 * File:   common.h
 * Author: francesco
 *
 * Created on 16 ottobre 2014, 0.00
 */

#ifndef COMMON_H
#define	COMMON_H

#define NALLOC(p,type,size,n) (p = (type)malloc(sizoef(size)*n))
#define MALLOC(p,type,size) (NALLOC(p,type,size,1))

#endif	/* COMMON_H */

