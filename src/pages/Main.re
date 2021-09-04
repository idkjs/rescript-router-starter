[@react.component]
let make = () =>
  <div className="section is-fullheight">
    <div className="container">
      <div className="column is-4 is-offset-4">
        <h1 className="is-size-1"> {"Main Page" |> React.string} </h1>
        <hr />
        <Link
          href="/login"
          className="is-size-4"
          activeClassName=Styles.activeNavItem>
          "Login"->React.string
        </Link>
        <p className="is-size-5"> {"or" |> React.string} </p>
        <Link
          href="/register"
          className="is-size-4"
          activeClassName=Styles.activeNavItem>
          "Register"->React.string
        </Link>
      </div>
    </div>
  </div>;
