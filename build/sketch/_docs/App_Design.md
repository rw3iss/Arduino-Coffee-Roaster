#line 1 "/Users/rw3iss/Documents/Arduino/Projects/Roaster/_docs/App_Design.md"
# ComponentBase:
-bubbles events up to parent to "redraw", ie. some child state changed.
-

// basically a view + event manager
# UI:
components;
renderer;
screen;

addComponent();
removeComponent();

drawComponents(screen);

onEvent(event):
    -handles ie. component state changes, and tells screen to redraw.
    -handles ie. control event such as "button pressed"

# ComponentRenderer:
draw(screen, components);
    -lays out the components on the screen, scaled according to its size and the components sizes
    -



# HomeView : View
-children: [ RowSelect ] ?

# RowSelect:
-children: [ ColumnSelect, ColumnSelect, ColumnSelect ];
-selectNext:
    -selet

# Need:


ViewStack or ViewManager:
-app starts, initializes, then:
    -sets up/initializes HomeView
        -HomeView has controls that, when clicked, fire events. Some may bubble up... and ViewManager can handle them to change the current page or do something.
            -some views should be able to fire "Control Events" to control the hardware (ie. set heater to temperature, turn fan on, etc)...
            -so if a button is clicked or a value is increased... this event gets picked up first by that view, which can handle/calculate the state change...
            -then this event will also probably raise other AppEvents? s
                -otherwise it would be handling passed-in callback props (ie. onIncreaseTemperature, etc)
                -better design is? View says "Set temperature to"


ControlInterface receives control event... passes to UI