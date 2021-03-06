#include "BirdBox.h"
#include "SimpleAudioEngine.h"
#include <iostream>

USING_NS_CC;
#define SCALE_RATIO 32

Bird2::Bird2(cocos2d::Layer *layer, b2World *world)
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
	bird = Sprite::create("ball.png");
   	bird->setPosition( Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	layer->addChild(bird,100);

	b2BodyDef ballBodyDef;
	ballBodyDef.type = b2_dynamicBody;
	ballBodyDef.position.Set((visibleSize.width/2 + origin.x)/SCALE_RATIO, (visibleSize.height/2 + origin.y)/SCALE_RATIO);
	ballBodyDef.userData = bird;

	birdbody = world->CreateBody(&ballBodyDef);

	b2CircleShape circle;
	circle.m_radius = 12.5/SCALE_RATIO;	//не соответствует размеру спрайта //без нуля - нулевой радиус!!!

	b2FixtureDef ballShapeDef;
	ballShapeDef.shape = &circle;
	ballShapeDef.density = 1.0f;
	ballShapeDef.friction = 0.2f;
	ballShapeDef.restitution = 40.0f;

	birdbody->CreateFixture(&ballShapeDef);
}

void Bird2::Fly(){
	birdbody->ApplyLinearImpulse( b2Vec2(0,5), birdbody->GetPosition(), true );	
}

