open Webapi.Dom;
open Webapi.Dom.DomRect;

type state = {
  canvasRef: ref(option(Dom.element))
};

type rect = {
	x: int,
	y: int,
	w: int,
	h: int,
}


let component = ReasonReact.reducerComponent("CanvasThing");

let setCanvasRef = (theRef, {ReasonReact.state}) => {
	state.canvasRef := Js.Nullable.toOption(theRef);
};


let get_mouse_pos_for_action = ( event, ref ) => {
	Js.log(event);


	let bgRectSrc = Webapi.Dom.Element.getBoundingClientRect(ref);
	let bgRect:rect = {
						x: Webapi.Dom.DomRect.left(bgRectSrc),
						y: Webapi.Dom.DomRect.top(bgRectSrc),
						w: Webapi.Dom.DomRect.right(bgRectSrc) - Webapi.Dom.DomRect.left(bgRectSrc),
						h: Webapi.Dom.DomRect.bottom(bgRectSrc) - Webapi.Dom.DomRect.top(bgRectSrc)
					};

	Js.log(bgRect);
	
};



let make = (_children) => {
	let handleClick = (event, self: ReasonReact.self(state, ReasonReact.noRetainedProps, unit)) => {
		/* Js.log(self.state); */

		switch (self.state.canvasRef^) {
			|	None => ()
			|	Some(r) => {
					get_mouse_pos_for_action(event, r);
					Canvas.fillRect( Canvas.getContext( r ), 0.0, 0.0, 100.0, 100.0);
				}
		};
	};



	{
	...component,
	initialState: () => {
    	{canvasRef: ref(None)}
    },
	reducer: ((), _) => ReasonReact.NoUpdate,
	render: self =>
		<div onClick=(self.handle(handleClick))>
			<canvas
				width="100"
				height="100"
				ref={self.handle(setCanvasRef)}
			/>
		</div>,
	}
};
