#import <Cocoa/Cocoa.h>
#import <OpenGL/OpenGL.h>
#import <OpenGL/gl3.h>

@interface MyOpenGLView : NSOpenGLView
{
}
@end

@implementation CocoaWin

- (id)initWithFrame:(NSRect)frame
{
	NSRect windowRect = NSMakeRect(10.0f, 10.0f, 800.0f, 600.0f);
	NSWindow *window = [[NSWindow alloc] initWithContentRect:windowRect
	styleMask:( NSResizableWindowMask | NSClosableWindowMask | NSTitledWindowMask)
	backing:NSBackingStoreBuffered defer:NO];
	[window makeKeyAndOrderFront:nil];

	NSOpenGLPixelFormatAttribute pixelFormatAttributes[] =
	{
		NSOpenGLPFAOpenGLProfile, NSOpenGLProfileVersion3_2Core,
		NSOpenGLPFAColorSize, 24,
		NSOpenGLPFAAlphaSize, 8,
		NSOpenGLPFADoubleBuffer,
		NSOpenGLPFAAccelerated,
		NSOpenGLPFANoRecovery,
		0
	};
	NSOpenGLPixelFormat *pixelFormat = [[NSOpenGLPixelFormat alloc] initWithAttributes:pixelFormatAttributes];
	self = [super initWithFrame:frame pixelFormat:pixelFormat];

	[[self openGLContext] makeCurrentContext];
}
