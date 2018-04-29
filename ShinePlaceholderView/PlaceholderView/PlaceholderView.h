
//  ShinePlaceholderView
//
//  Created by BraveShine on 2018/4/29.
//  Copyright © 2018年 BraveShine. All rights reserved.
//

#import <UIKit/UIKit.h>


typedef NS_ENUM(NSUInteger, PlaceholderViewType) {
    PlaceholderViewTypeImage,
    PlaceholderViewTypeAnimation,
};

@interface PlaceholderViewConfiguration : NSObject

/** 占位文字*/
@property (nonatomic,strong) NSString * placeholder;

/** 占位图片*/
@property (nonatomic,strong) UIImage * placeholderImage;

/** 占位文字的颜色*/
@property (nonatomic,strong) UIColor *placeholderColor;

/** 占位GIF图片数组 */
@property (nonatomic,strong) NSArray<UIImage *> *animationImages;

/** 占位图片类型 单图或者GIF*/
@property (nonatomic,assign)PlaceholderViewType type;

/** GIF一次完整显示时间 通过此参数控制GIF速度*/
@property (nonatomic) NSTimeInterval animationDuration;

+(instancetype)shareConfiguration;

@end

typedef void(^PlaceholderImageClickBlock)(void);

typedef void(^PlaceholderTextClickBlock)(void);




@interface PlaceholderView : UIView

/** 内容区域*/
@property (weak, nonatomic) IBOutlet UIView *contentView;

/** 占位图UIImageView*/
@property (weak, nonatomic) IBOutlet UIImageView *placeholderImageView;

/** 占位文字按钮*/
@property (weak, nonatomic) IBOutlet UIButton *placeholderButton;

/** 占位图向下偏移量 （并不是内容区域向下偏移量，是整个视图的向下偏移量） */
@property (nonatomic,assign) CGFloat ofset;

/** 占位图片*/
@property (nonatomic,strong) UIImage * placeholderImage;

/** 占位文字*/
@property (nonatomic,strong) NSString * placeholder;

/** 占位文字的颜色*/
@property (nonatomic,strong) UIColor *placeholderColor;

/** 占位GIF图片数组*/
@property (nonatomic,strong) NSArray<UIImage *> *animationImages;

/** GIF一次完整显示时间 通过此参数控制GIF速度*/
@property (nonatomic) NSTimeInterval animationDuration;

/** 占位图片类型 单图或者GIF*/
@property (nonatomic,assign)PlaceholderViewType type;

/** 图片区域点击回调*/
@property (nonatomic,copy) PlaceholderImageClickBlock imageClickBlock;

/** 文字区域点击回调*/
@property (nonatomic,copy) PlaceholderTextClickBlock textClickBlock;


/** 保留父视图，便于显示操作*/
@property (nonatomic,weak) UIView *parent;

/**
 创建视图

 @param view 需要显示占位视图的视图
 @return 返回占位视图的实例
 */
- (instancetype)initWithView:(UIView *)view;

/**
 改视图的占位视图

 @param view 视图
 @return 占位视图
 */
+(instancetype)placeholderViewForView:(UIView *)view;

/**
 隐藏视图的占位视图

 @param view 视图
 */
+(void)hidenPlaceholderViewForView:(UIView *)view;

/** 显示占位视图*/
-(void)show;

/** 隐藏占位视图*/
-(void)dismiss;

@end