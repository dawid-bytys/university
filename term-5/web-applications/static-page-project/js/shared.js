class SharedHeader extends HTMLElement {
  connectedCallback() {
    this.innerHTML = `
      <header class="header">
        <div class="logo-container">
          <img src="../assets/img/logo.png" alt="logo" />
        </div>
        <button id="hamburger" class="hamburger-btn">
          <span class="hamburger-line"></span>
        </button>
        <nav id="navigation" class="navigation">
          <ul class="navigation-list">
            <li>
              <a href="index.html" id="navigation-link">Home</a>
            </li>
            <li>
              <a href="#services" id="navigation-link">Services</a>
            </li>
            <li>
              <a href="#portfolio" id="navigation-link">Portfolio</a>
            </li>
            <li>
              <a href="#contact" id="navigation-link">Contact</a>
            </li>
          </ul>
        </nav>
    </header>
    `;
  }
}

customElements.define("shared-header", SharedHeader);

class SharedFooter extends HTMLElement {
  connectedCallback() {
    this.innerHTML = `
      <footer class="footer">
        <div>
          <img src="../assets/img/logo.png" alt="logo" />
        </div>
        <div>
          <ul class="footer-list">
            <li>
              <a href="../html/support.html">Support</a>
            </li>
            <li>
              <a href="../html/policy.html">Privacy Policy</a>
            </li>
            <li>
              <a href="../html/terms.html">Terms of Service</a>
            </li>
          </ul>
        </div>
        <div>
          <p>© 2024 Enver, All right reserved</p>
        </div>
      </footer>
    `;
  }
}

customElements.define("shared-footer", SharedFooter);
