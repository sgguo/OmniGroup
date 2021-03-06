// Copyright 2010-2019 Omni Development, Inc. All rights reserved.
//
// This software may only be used and reproduced according to the
// terms in the file OmniSourceLicense.html, which should be
// distributed with this project and can also be found at
// <http://www.omnigroup.com/developer/sourcecode/sourcelicense/>.

#import <Foundation/NSObject.h>

@interface OUIKeyboardNotifier : NSObject

+ (instancetype)sharedNotifier;

/// The last known height for the docked keyboard; avoid this height at the bottom of the screen when laying out in response to a keyboard notification.
@property (nonatomic, readonly) CGFloat lastKnownKeyboardHeight;
@property (nonatomic, readonly, getter=isKeyboardVisible) BOOL keyboardVisible;

@property(nonatomic,readonly) NSTimeInterval lastAnimationDuration;
@property(nonatomic,readonly) UIViewAnimationCurve lastAnimationCurve;

@property (nonatomic, weak) UIView *accessoryToolbarView;

/// Returns the minimum Y coordinate of the last known keyboard rect, translated to the coordinate space of the given view. The return value for this method is useful in calculating visible areas for an arbitrarily deep view in the hierarchy (e.g. for avoiding the keyboard or updating scroll insets).
- (CGFloat)minimumYPositionOfLastKnownKeyboardInView:(UIView *)view;

@end

#pragma mark -

#ifdef DEBUG

@interface OUIKeyboardNotifier (Debug)

+ (BOOL)hasSharedNotifier;

@end

#endif

#pragma mark -

extern NSString * const OUIKeyboardNotifierKeyboardWillChangeFrameNotification;
extern NSString * const OUIKeyboardNotifierKeyboardDidChangeFrameNotification;

extern NSString * const OUIKeyboardNotifierKeyboardWillShowNotification;
extern NSString * const OUIKeyboardNotifierKeyboardDidShowNotification;
extern NSString * const OUIKeyboardNotifierKeyboardWillHideNotification;
extern NSString * const OUIKeyboardNotifierKeyboardDidHideNotification;

extern NSString * const OUIKeyboardNotifierOriginalUserInfoKey;
extern NSString * const OUIKeyboardNotifierLastKnownKeyboardHeightKey;
