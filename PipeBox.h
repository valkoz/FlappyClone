#ifndef __PIPEBOX_H__
#define __PIPEBOX_H__

#include "cocos2d.h"
#include "Definitions.h"
#include "Box2D/Box2D.h"


class Pipe2 : public cocos2d::Layer
{
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	void MakePipeBody(cocos2d::Layer *layer, b2World *world, cocos2d::Rect a);
public:
    Pipe2();
    void SpawnPipe(cocos2d::Layer *layer, b2World *world);

};

#endif // __PIPEBOX_H__
