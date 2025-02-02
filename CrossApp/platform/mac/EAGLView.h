
#ifndef __EAGLVIEW_MAC_H__
#define __EAGLVIEW_MAC_H__

#import <Cocoa/Cocoa.h>
#import "ccConfig.h"

//PROTOCOLS:

@protocol MacEventDelegate <NSObject>
// Mouse
- (void)mouseDown:(NSEvent *)theEvent;
- (void)mouseUp:(NSEvent *)theEvent;
- (void)mouseMoved:(NSEvent *)theEvent;
- (void)mouseDragged:(NSEvent *)theEvent;
- (void)rightMouseDown:(NSEvent*)event;
- (void)rightMouseDragged:(NSEvent*)event;
- (void)rightMouseUp:(NSEvent*)event;
- (void)otherMouseDown:(NSEvent*)event;
- (void)otherMouseDragged:(NSEvent*)event;
- (void)otherMouseUp:(NSEvent*)event;
- (void)scrollWheel:(NSEvent *)theEvent;
- (void)mouseEntered:(NSEvent *)theEvent;
- (void)mouseExited:(NSEvent *)theEvent;


// Keyboard
- (void)keyDown:(NSEvent *)theEvent;
- (void)keyUp:(NSEvent *)theEvent;
- (void)flagsChanged:(NSEvent *)theEvent;

// Touches
- (void)touchesBeganWithEvent:(NSEvent *)event;
- (void)touchesMovedWithEvent:(NSEvent *)event;
- (void)touchesEndedWithEvent:(NSEvent *)event;
- (void)touchesCancelledWithEvent:(NSEvent *)event;

#if CC_DIRECTOR_MAC_USE_DISPLAY_LINK_THREAD
- (void)queueEvent:(NSEvent*)event selector:(SEL)selector;
#endif

@end

/** MacGLView
 
 Only available for Mac OS X
 */
@interface EAGLView : NSOpenGLView{
	id<MacEventDelegate> eventDelegate_;

	BOOL isFullScreen_;
	NSWindow		*fullScreenWindow_;
	
	// cache
	NSWindow		*windowGLView_;
    NSView          *superViewGLView_;
    NSRect          originalWinRect_; // Original size and position
        
    NSString *              markedText_;
}

@property (nonatomic, readwrite, assign) id<MacEventDelegate> eventDelegate;

// whether or not the view is in fullscreen mode
@property (nonatomic, readonly) BOOL isFullScreen;

// initializes the MacGLView with a frame rect and an OpenGL context
- (id) initWithFrame:(NSRect)frameRect shareContext:(NSOpenGLContext*)context;

- (id) initWithFrame:(NSRect)frameRect pixelFormat:(NSOpenGLPixelFormat *)format;

/** uses and locks the OpenGL context */
-(void) lockOpenGLContext;

/** unlocks the openGL context */
-(void) unlockOpenGLContext;

/** returns the depth format of the view in BPP */
- (NSUInteger) depthFormat;

// get the view object
+(id) sharedEGLView;

-(int) getWidth;
-(int) getHeight;
-(void) swapBuffers;

-(void) setFullScreen:(BOOL)fullscreen;

@end
#endif // __EAGLVIEW_MAC_H__

